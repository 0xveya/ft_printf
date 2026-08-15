*This project has been created as part of the 42 curriculum by sfurst.*

## Description

`ft_printf` is a small C static library named `libftprintf.a`. Its goal is to
reimplement the core behavior of the standard `printf()` function without using
libc's internal formatting machinery.

The mandatory subject requires support for the conversions `cspdiuxX%`. This
project also explores the central idea behind `printf`: **variadic functions**.
Arguments are read from a `va_list`, parsed into a small formatting structure,
and dispatched to the matching printer.

In this version, the implementation is organized around a `t_format` struct that
stores parsed flags, width, precision, and conversion type. Output passes through
a 4096-byte writer so formatting does not require one system call per character.

## Instructions

Build the library:

```sh
make
```

Build through the bonus target:

```sh
make bonus
```

The bonus parser and formatting paths are integrated into the same source files
as the mandatory implementation. For that reason, `make bonus` depends on the
same `libftprintf.a` target instead of compiling a second set of `_bonus` files.
If the library is already current, Make reports that there is nothing to rebuild.

The integrated extensions parse the flags `-`, `0`, `#`, `+`, and space, along
with field width and precision. Signed decimal formatting applies sign, padding,
alignment, and precision rules; strings and characters apply their relevant
width, alignment, and precision rules; hexadecimal formatting applies the `#`
prefix. The mandatory conversions `cspdiuxX%` remain available from the same
library.

Remove object files:

```sh
make clean
```

Remove object files and `libftprintf.a`:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

Build and run the evaluator-oriented comparison program:

```sh
make test
```

The test output is split into sections and compares both rendered output and
return values against libc `printf`. It covers all required conversions,
integer limits, null values, width, precision, conflicting flags, empty strings,
embedded NUL characters, and a percent conversion at the end of a format.

Use the library in another C file:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

Minimal example:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("char: %c\n", 'A');
	ft_printf("str: %s\n", "hello");
	ft_printf("ptr: %p\n", (void *)0x42);
	ft_printf("int: %d %i\n", 42, -42);
	ft_printf("uint: %u\n", 42u);
	ft_printf("hex: %x %X\n", 255u, 255u);
	ft_printf("percent: %%\n");
	return (0);
}
```

## Algorithm And Data Structure

The implementation follows a small pipeline:

1. `ft_printf()` scans the format string from left to right.
2. When a normal character is found, it is written directly.
3. When `%` is found, parsing begins.
4. The parser reads flags, width, precision, and the final conversion type into
   a `t_format` struct.
5. A dispatcher selects the right printing function for `c`, `s`, `p`, `d`,
   `i`, `u`, `x`, `X`, or `%`.
6. Each printer writes through a shared buffer and the final result reports the
   number of produced characters.
7. The writer flushes when full and once more before `ft_printf()` returns, so
   the total result matches the `printf()` contract.

### Core data structure

```c
typedef struct s_format
{
	uint32_t	flags;
	int			width;
	int			precision;
	t_conv		type;
} t_format;
```

This structure was chosen because `printf` formatting is naturally a compact set
of orthogonal fields. The five boolean flags occupy bits in one integer, while a
precision of `-1` means that no precision was provided. This removes separate
boolean fields without hiding the parser state.

For signed integer formatting, an additional helper struct is used to precompute
sign, digit count, zero padding, and outer padding before printing. This avoids
recomputing formatting values across multiple branches.

### Integer digit conversion

Integers are rendered backwards into a fixed-size local buffer and then written
as one span. Decimal conversion handles two digits per division by 100 and uses
a lookup string containing `00` through `99`. Compared with taking one digit per
division by 10, this roughly halves the number of division and remainder steps.

Hexadecimal conversion does not divide at all. Because base 16 is a power of
two, the next digit is selected with a four-bit mask and the value advances with
a four-bit right shift. The same routine formats pointers with a 64-bit input.

### Buffered output

The writer accumulates up to 4096 bytes before calling `write()`. This matters
most for width and precision padding, where the older implementation issued one
system call for every repeated character.

A system call crosses from the program into the kernel. That fixed transition,
argument validation, file-descriptor lookup, and output handling cost far more
than placing one byte in an already allocated array. Calling `write()` for every
space in `%4096d`, for example, repeats that overhead thousands of times. The
buffer turns those small writes into a few large writes.

Strings, padding, signs, prefixes, and converted digits all enter the same
`t_writer` buffer. Appending follows this loop:

1. Copy as much of the new span as fits in the remaining buffer space.
2. Flush the buffer when it becomes full.
3. Continue with the unconsumed part of the span.
4. Flush the remaining bytes once before `ft_printf()` returns.

Output shorter than 4096 bytes normally needs one `write()` call. Longer output
is split into complete 4096-byte flushes followed by one final partial flush, so
there is no maximum formatted length imposed by the buffer. A single string
larger than the buffer passes through the same loop without a temporary
allocation.

The flush function also handles short writes. It advances by the number of bytes
actually accepted and retries the remainder of the buffer. The writer counts
bytes when they are appended, preserves that total across flushes, and records a
sticky error if `write()` returns zero or a negative value. Once an error is set,
formatting stops and `ft_printf()` returns `-1`.

### What SIMD and AVX2 mean

SIMD means Single Instruction, Multiple Data. A scalar byte loop handles one
byte per iteration. An AVX2 instruction operates on a 256-bit register, which
holds 32 independent bytes. One instruction can therefore load, store, or
compare a complete 32-byte block.

AVX2 is the particular x86 instruction-set extension used here. It is a CPU
feature, not a C library or operating-system feature. The intrinsics from
`<immintrin.h>` are compiler-provided interfaces to those machine instructions.
Other architectures expose the same general SIMD idea through different
instruction sets, such as NEON on ARM.

Both vectorized helpers use `__attribute__((target("avx2")))`. GCC or Clang can
therefore emit AVX2 for those functions without a global `-mavx2` flag. The
attribute does not perform runtime CPU detection or provide a scalar fallback.
The compiler may accept the program even when the CPU that later runs it lacks
AVX2, in which case execution may stop with an illegal-instruction fault.

The intrinsics request vector operations explicitly. This matters for the
subject's compile command because it has no optimization flag and does not ask
the compiler to discover and auto-vectorize ordinary scalar loops.

### SIMD `strlen`

The declaration in the internal header applies AVX2 only to this function:

```c
int ft_strlen(const char *s) __attribute__((target("avx2")));
```

The function keeps the original pointer and a moving scan pointer:

```c
p = s;
```

`s` remains fixed so `p - s` can produce the final length. Before using an
aligned vector load, the scalar prefix advances `p` to the next address divisible
by 32:

```c
while (((uintptr_t)p & 31) != 0)
{
    if (*p == '\0')
        return ((int)(p - s));
    p++;
}
```

Casting the pointer to `uintptr_t` exposes its numeric address. Because 32 is a
power of two, the lowest five address bits are zero exactly when the pointer is
32-byte aligned; `& 31` tests those bits. Every prefix byte is checked before
advancing, so a short string can finish without entering the vector loop.

```c
zero = _mm256_setzero_si256();
```

This creates a 256-bit integer vector whose 32 byte lanes are all zero. It is
created once and reused for every block.

```c
v = _mm256_load_si256((const __m256i *)p);
```

The cast presents the current byte address as a pointer to one 256-bit vector.
`_mm256_load_si256()` loads the next 32 bytes into `v` and requires the alignment
established by the scalar prefix.

The loaded bytes are compared with the zero vector and reduced to a normal
integer mask:

```c
mask = (unsigned int)_mm256_movemask_epi8(
        _mm256_cmpeq_epi8(v, zero));
```

`_mm256_cmpeq_epi8()` performs 32 independent byte comparisons. An equal lane
becomes `0xff`; a different lane becomes `0x00`.
`_mm256_movemask_epi8()` takes the high bit from each result lane and packs those
bits into a 32-bit integer. Bit zero describes `p[0]` and bit 31 describes
`p[31]`, so each set bit marks a NUL byte.

```c
if (mask != 0)
    return ((int)(p - s) + __builtin_ctz(mask));
```

A nonzero mask means the block contains at least one terminator.
`__builtin_ctz(mask)` counts the zero bits below the least-significant set bit,
which is the index of the first NUL byte. It is called only after the nonzero
check because `ctz(0)` is undefined. `p - s` counts all preceding bytes, and the
lane index completes the string length.

```c
p += 32;
```

When the mask is zero, all 32 bytes are nonzero and the pointer advances by one
complete vector. The unconditional vector loop repeats until a terminator is
found, as required for a valid C string.

Aligning before the vector loop lets the function use `_mm256_load_si256()`.
Because common page sizes are multiples of 32, an aligned 32-byte load does not
cross into the next page. This avoids reading across an inaccessible page after
a valid string terminator near a page boundary.

### SIMD copy

The internal declaration enables AVX2 for the copy helper:

```c
void ft_memcpy(char *dst, const char *src,
    size_t len) __attribute__((target("avx2")));
```

The vector loop runs only while a complete block is available:

```c
while (len >= 32)
```

This guard prevents a 32-byte load or store from extending beyond the requested
range. Each iteration performs one vector load and one vector store:

```c
_mm256_storeu_si256((__m256i *)dst,
    _mm256_loadu_si256((const __m256i *)src));
```

The inner intrinsic loads 32 source bytes into a temporary vector before the
outer intrinsic stores that vector to the destination. The pointer casts expose
the byte addresses as vector addresses. The `u` suffix means unaligned, so
neither pointer must be divisible by 32. These operations do not provide
`memmove()` semantics; this helper is called only with non-overlapping regions.

```c
dst += 32;
src += 32;
len -= 32;
```

Both pointers advance past the copied block and the remaining byte count drops
by 32. Pointer updates and the loop branch therefore happen once per block
instead of once per byte.

```c
while (len-- > 0)
    *dst++ = *src++;
```

After the vector loop, zero to 31 bytes remain. The scalar tail copies one byte
and advances both pointers until the original requested length is exhausted.
When `len` is zero, the loop body does not run.

SIMD does not guarantee a 32-times speedup. System calls, cache state, memory
bandwidth, short inputs, and scalar prefix or tail work still matter. It removes
much of the per-byte loop overhead for sufficiently large strings and copies.

### Benchmark against the older version

The older version is commit `4268c48b`, before the buffered writer, AVX2 memory
helpers, and fixed-width digit conversion. Lower is better. Each value is the
median of five runs with output redirected to `/dev/null`.

| Workload | Calls | Older version | Current version | Speedup |
| --- | ---: | ---: | ---: | ---: |
| 10-digit decimal plus newline | 100,000 | 143.6 ms | 22.4 ms | 6.4x |
| Width-4096 decimal plus newline | 2,000 | 866.2 ms | 83.6 ms | 10.4x |

Measurements were taken on an Intel Core i5-11500H with GCC 16.2.1 and the
project's `-Wall -Wextra -Werror` flags, without an optimization flag. The
benchmark measures the combined design rather than claiming that digit lookup,
SIMD, or buffering alone accounts for the full difference. Results will vary by
CPU, kernel, and output target.

## Source Overview

- `printf.c`: main loop over the format string.
- `parse.c`: parses flags, width, precision, and conversion sequence.
- `parse_utils.c`: helper functions for flag detection and conversion lookup.
- `printf_dispatch.c`: dispatches a parsed format to the right print function.
- `writer.c`: buffers output, flushes writes, and tracks errors and length.
- `integer_digits.c`: fixed-width decimal, hexadecimal, and generic conversion.
- `memcpy.c` and `strlen.c`: AVX2 bulk memory helpers.
- `print_char.c`: `%c` handling.
- `print_string.c`: `%s` handling.
- `print_pointer.c`: `%p` handling.
- `print_int.c`: `%d` and `%i` handling.
- `print_uint.c`: `%u` handling.
- `print_hex.c`: `%x` and `%X` handling.
- `print_percent.c`: `%%` handling.

## Notes On Design

This project uses a small output writer, not libc's internal stream machinery.
The buffer belongs to one `ft_printf()` call and is flushed directly with
`write()`.

Compared with `glibc`, this project is intentionally tiny and educational:

- `glibc` has a large, optimized, highly portable formatting subsystem.
- this project keeps the control flow readable and close to the subject's scope.
- parsing is represented explicitly through `t_format` rather than through a much
  larger internal formatting engine.

By design, the subject in general does **not** provide compile-time static
checks to verify that the number of provided arguments matches the format string
or that every argument type matches its conversion specifier. As with classic
C-style variadic formatting, correctness depends on the caller using the
function properly.

## Resources

Classic references used for the project and for understanding `printf`:

- the 42 subject
- [`printf(3)`](https://man7.org/linux/man-pages/man3/printf.3.html)
- [`stdarg(3)`](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [`write(2)`](https://man7.org/linux/man-pages/man2/write.2.html)
- [Variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- [glibc `printf` source](https://github.com/lattera/glibc/blob/master/stdio-common/printf.c)
- [GCC x86 function attributes](https://gcc.gnu.org/onlinedocs/gcc/x86-Function-Attributes.html)
  documents per-function `target("avx2")` compilation.
- [Clang attribute reference](https://clang.llvm.org/docs/AttributeReference.html#target)
  documents Clang's compatible GNU-style `target` attribute.
- [GCC bit-operation builtins](https://gcc.gnu.org/onlinedocs/gcc/Bit-Operation-Builtins.html)
  documents `__builtin_ctz` and its undefined zero-input case.
- [Intel Intrinsics Guide](https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html)
  documents the AVX2 load, store, compare, and movemask intrinsics.
- [Single instruction, multiple data](https://en.wikipedia.org/wiki/Single_instruction%2C_multiple_data)
  gives an overview of SIMD and data-level parallelism.
- [Everyone Should Know SIMD](https://mitchellh.com/writing/everyone-should-know-simd)
  explains the common vector-loop shape used by the memory helpers.
- [winstonallo/libft](https://github.com/winstonallo/libft) inspired the SIMD
  experiment, especially its `ft_strlen()` implementation.

AI was used to help:

- extract and summarize the README requirements from the subject PDF
- draft and structure this README

All code changes were reviewed locally, rebuilt with `make`, and checked with
`norminette`.
