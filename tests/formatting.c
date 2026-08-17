/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   formatting.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/17 23:40:00 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/17 23:40:00 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	show_returns(int expected, int actual)
{
	printf("returns: printf=%d, ft_printf=%d\n", expected, actual);
}

void	test_width_and_alignment(void)
{
	int	expected;
	int	actual;

	printf("\n=== width and alignment ===\n");
	expected = printf("printf:    [%10s] [%-10s] [%5c] [%-5c]\n", "cat", "cat",
			'Z', 'Z');
	actual = ft_printf("ft_printf: [%10s] [%-10s] [%5c] [%-5c]\n", "cat", "cat",
			'Z', 'Z');
	show_returns(expected, actual);
	expected = printf("printf:    [%8d] [%-8d] [%08d] [%+d] [% d]\n", 42, 42,
			-42, 42, 42);
	actual = ft_printf("ft_printf: [%8d] [%-8d] [%08d] [%+d] [% d]\n", 42, 42,
			-42, 42, 42);
	show_returns(expected, actual);
}

void	test_precision_and_flags(void)
{
	const char	*format;
	const char	*flags;
	int			expected;
	int			actual;

	printf("\n=== precision and flag interactions ===\n");
	format = "printf:    [%.0d] [%.0d] [%.5d] [%8.5d] [%08.5d]\n";
	expected = printf(format, 0, 7, 42, 42, 42);
	format = "ft_printf: [%.0d] [%.0d] [%.5d] [%8.5d] [%08.5d]\n";
	actual = ft_printf(format, 0, 7, 42, 42, 42);
	show_returns(expected, actual);
	flags = "printf:    [%#x] [%#X] [%#x] [%+ d] [%-08d]\n";
	expected = printf(flags, 42u, 42u, 0u, 42, 42);
	flags = "ft_printf: [%#x] [%#X] [%#x] [%+ d] [%-08d]\n";
	actual = ft_printf(flags, 42u, 42u, 0u, 42, 42);
	show_returns(expected, actual);
	expected = printf("printf:    [%.3s] [%8.3s] [%-8.3s]\n", "abcdef",
			"abcdef", "abcdef");
	actual = ft_printf("ft_printf: [%.3s] [%8.3s] [%-8.3s]\n", "abcdef",
			"abcdef", "abcdef");
	show_returns(expected, actual);
}

void	test_percent_and_characters(void)
{
	int	expected;
	int	actual;

	printf("\n=== percent, empty strings, and embedded NUL ===\n");
	expected = printf("printf:    empty=[%s] percent-at-end=[%%]\n", "");
	actual = ft_printf("ft_printf: empty=[%s] percent-at-end=[%%]\n", "");
	show_returns(expected, actual);
	printf("printf:    ");
	expected = printf("char NUL: before[%c]after\n", '\0');
	ft_printf("ft_printf: ");
	actual = ft_printf("char NUL: before[%c]after\n", '\0');
	show_returns(expected, actual);
	printf("note: a lone trailing %% is malformed and is outside the "
		"subject API\n");
}
