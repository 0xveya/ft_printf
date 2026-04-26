*This project has been created as part of the 42 curriculum by sfurst.*

## Description

`ft_printf` is a small C static library named `libftprintf.a`. Its goal is to
reimplement the core behavior of the standard `printf()` function without using
libc's internal formatting machinery.

The mandatory subject requires support for the conversions `cspdiuxX%`. This
project also explores the central idea behind `printf`: **variadic functions**.
Arguments are read from a `va_list`, parsed into a small formatting structure,
normalized according to `printf` rules, and then dispatched to the matching
printer.

In this version, the implementation is organized around a `t_format` struct that
stores parsed flags, width, precision, and conversion type. The code is split
into small source files so the parsing, normalization, dispatch, and rendering
steps remain easy to test and reason about.

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
5. A normalization step resolves conflicting flags such as `-` overriding `0`,
   `+` overriding space, and precision disabling zero-padding for numeric
   conversions.
6. A dispatcher selects the right printing function for `c`, `s`, `p`, `d`,
   `i`, `u`, `x`, `X`, or `%`.
7. Each printer returns the number of written characters so the total result
   matches the `printf()` contract.

### Core data structure

```c
typedef struct s_format
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		has_precision;
	t_conv	type;
}t_format;
```

This structure was chosen because `printf` formatting is naturally a compact set
of orthogonal fields. A struct keeps parsing state explicit and makes the code
more extensible than passing many separate integers between functions.

For signed integer formatting, an additional helper struct is used to precompute
sign, digit count, zero padding, and outer padding before printing. This avoids
recomputing formatting values across multiple branches.

## Source Overview

- `printf.c`: main loop over the format string.
- `parse.c`: parses flags, width, precision, and conversion sequence.
- `parse_utils.c`: helper functions for flag detection and conversion lookup.
- `normalize.c`: resolves conflicting formatting rules after parsing.
- `printf_dispatch.c`: dispatches a parsed format to the right print function.
- `helpers.c`: character output, repeated character output, and format init.
- `helpers2.c`: local utility helpers such as `ft_strlen`.
- `print_char.c`: `%c` handling.
- `print_string.c`: `%s` handling.
- `print_pointer.c`: `%p` handling.
- `print_int.c`: `%d` and `%i` handling.
- `print_uint.c`: `%u` handling.
- `print_hex.c`: `%x` and `%X` handling.
- `print_percent.c`: `%%` handling.

## Notes On Design

This project intentionally does **not** copy libc's internal buffering model.
The subject explicitly says not to reimplement the original buffer management, so
this version uses direct writes and small helper functions.

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
