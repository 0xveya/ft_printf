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
   the total result
   matches the `printf()` contract.

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

### Buffered and vectorized helpers

The writer accumulates up to 4096 bytes before calling `write()`. This matters
most for width and precision padding, where the older implementation issued one
system call for every repeated character. `ft_memcpy` and `ft_strlen` use AVX2
to process 32-byte blocks, then use a scalar tail where required. The
function-level `target("avx2")` attribute avoids enabling AVX2 for unrelated
functions, but there is no runtime fallback for CPUs without AVX2.

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

Compared with Zig's `std.debug.print`, this project follows the usual C
variadic approach instead of compile-time checked formatting.

By design, the subject in general does **not** provide compile-time static
checks to verify that the number of provided arguments matches the format string
or that every argument type matches its conversion specifier. As with classic
C-style variadic formatting, correctness depends on the caller using the
function properly.

## Resources

Classic references used for the project and for understanding `printf`:

- the 42 subject
- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- Variadic functions in C:
  <https://www.geeksforgeeks.org/c/variadic-functions-in-c/>
- glibc `printf` source:
  <https://github.com/lattera/glibc/blob/master/stdio-common/printf.c>
- Zig `std.debug.print` documentation, used only as a brief comparison point:
  <https://ziglang.org/documentation/0.16.0/std/#std.debug.print>

AI was used to help:

- extract and summarize the README requirements from the subject PDF
- draft and structure this README

All code changes were reviewed locally, rebuilt with `make`, and checked with
`norminette`.
