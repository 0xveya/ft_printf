#include "ft_printf.h"

#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static void	section(const char *title)
{
	printf("\n=== %s ===\n", title);
}

static void	show_returns(int expected, int actual)
{
	printf("returns: printf=%d, ft_printf=%d\n", expected, actual);
}

static void	test_basic_conversions(void)
{
	int	expected;
	int	actual;

	section("basic conversions");
	expected = printf("printf:    [%c] [%s] [%p] [%d] [%i] [%u] [%x] [%X] [%%]\n",
		'A', "hello", (void *)(uintptr_t)0x42, 42, -42, 42u, 255u, 255u);
	actual = ft_printf("ft_printf: [%c] [%s] [%p] [%d] [%i] [%u] [%x] [%X] [%%]\n",
		'A', "hello", (void *)(uintptr_t)0x42, 42, -42, 42u, 255u, 255u);
	show_returns(expected, actual);
}

static void	test_integer_limits(void)
{
	int	expected;
	int	actual;

	section("integer limits and zero");
	expected = printf("printf:    d=[%d] [%d] [%d] u=[%u] [%u]\n",
		INT_MIN, 0, INT_MAX, 0u, UINT_MAX);
	actual = ft_printf("ft_printf: d=[%d] [%d] [%d] u=[%u] [%u]\n",
		INT_MIN, 0, INT_MAX, 0u, UINT_MAX);
	show_returns(expected, actual);
	expected = printf("printf:    hex=[%x] [%x] [%X]\n",
		0u, UINT_MAX, UINT_MAX);
	actual = ft_printf("ft_printf: hex=[%x] [%x] [%X]\n",
		0u, UINT_MAX, UINT_MAX);
	show_returns(expected, actual);
}

static void	test_null_values(void)
{
	char	*null_string;
	void	*null_pointer;
	int		expected;
	int		actual;

	null_string = NULL;
	null_pointer = NULL;
	section("null values");
	expected = printf("printf:    string=[%s] pointer=[%p]\n",
		null_string, null_pointer);
	actual = ft_printf("ft_printf: string=[%s] pointer=[%p]\n",
		null_string, null_pointer);
	show_returns(expected, actual);
	printf("ft_printf(NULL) return: %d\n", ft_printf(NULL));
}

static void	test_width_and_alignment(void)
{
	int	expected;
	int	actual;

	section("width and alignment");
	expected = printf("printf:    [%10s] [%-10s] [%5c] [%-5c]\n",
		"cat", "cat", 'Z', 'Z');
	actual = ft_printf("ft_printf: [%10s] [%-10s] [%5c] [%-5c]\n",
		"cat", "cat", 'Z', 'Z');
	show_returns(expected, actual);
	expected = printf("printf:    [%8d] [%-8d] [%08d] [%+d] [% d]\n",
		42, 42, -42, 42, 42);
	actual = ft_printf("ft_printf: [%8d] [%-8d] [%08d] [%+d] [% d]\n",
		42, 42, -42, 42, 42);
	show_returns(expected, actual);
}

static void	test_precision_and_flags(void)
{
	const char	*precision_fmt;
	const char	*flags_fmt;
	int			expected;
	int			actual;

	precision_fmt = "printf:    [%.0d] [%.0d] [%.5d] [%8.5d] [%08.5d]\n";
	flags_fmt = "printf:    [%#x] [%#X] [%#x] [%+ d] [%-08d]\n";
	section("precision and flag interactions");
	expected = printf(precision_fmt, 0, 7, 42, 42, 42);
	precision_fmt = "ft_printf: [%.0d] [%.0d] [%.5d] [%8.5d] [%08.5d]\n";
	actual = ft_printf(precision_fmt, 0, 7, 42, 42, 42);
	show_returns(expected, actual);
	expected = printf(flags_fmt, 42u, 42u, 0u, 42, 42);
	flags_fmt = "ft_printf: [%#x] [%#X] [%#x] [%+ d] [%-08d]\n";
	actual = ft_printf(flags_fmt, 42u, 42u, 0u, 42, 42);
	show_returns(expected, actual);
	expected = printf("printf:    [%.3s] [%8.3s] [%-8.3s]\n",
		"abcdef", "abcdef", "abcdef");
	actual = ft_printf("ft_printf: [%.3s] [%8.3s] [%-8.3s]\n",
		"abcdef", "abcdef", "abcdef");
	show_returns(expected, actual);
}

static void	test_percent_and_characters(void)
{
	int	expected;
	int	actual;

	section("percent, empty strings, and embedded NUL");
	expected = printf("printf:    empty=[%s] percent-at-end=[%%]\n", "");
	actual = ft_printf("ft_printf: empty=[%s] percent-at-end=[%%]\n", "");
	show_returns(expected, actual);
	printf("printf:    ");
	expected = printf("char NUL: before[%c]after\n", '\0');
	ft_printf("ft_printf: ");
	actual = ft_printf("char NUL: before[%c]after\n", '\0');
	show_returns(expected, actual);
	printf("note: a lone trailing %% is malformed and is outside the subject API\n");
}

int	main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	test_basic_conversions();
	test_integer_limits();
	test_null_values();
	test_width_and_alignment();
	test_precision_and_flags();
	test_percent_and_characters();
	return (0);
}
