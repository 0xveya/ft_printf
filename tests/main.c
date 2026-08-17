/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/17 23:25:23 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/17 23:25:24 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tests.h"
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
	int		expected;
	int		actual;

	section("basic conversions");
	expected = printf("printf:    [%c] [%s] [%p] [%d] [%i] "
			"[%u] [%x] [%X] [%%]\n",
			'A', "hello", (void *)(uintptr_t)0x42, 42, -42, 42u, 255u, 255u);
	actual = ft_printf("ft_printf: [%c] [%s] [%p] [%d] [%i] "
			"[%u] [%x] [%X] [%%]\n",
			'A', "hello", (void *)(uintptr_t)0x42, 42, -42, 42u, 255u, 255u);
	show_returns(expected, actual);
}

static void	test_integer_limits_and_nulls(void)
{
	char	*null_string;
	void	*null_pointer;
	int		expected;
	int		actual;

	section("integer limits and zero");
	expected = printf("printf:    d=[%d] [%d] [%d] u=[%u] [%u]\n", INT_MIN, 0,
			INT_MAX, 0u, UINT_MAX);
	actual = ft_printf("ft_printf: d=[%d] [%d] [%d] u=[%u] [%u]\n", INT_MIN, 0,
			INT_MAX, 0u, UINT_MAX);
	show_returns(expected, actual);
	expected = printf("printf:    hex=[%x] [%x] [%X]\n", 0u, UINT_MAX,
			UINT_MAX);
	actual = ft_printf("ft_printf: hex=[%x] [%x] [%X]\n", 0u, UINT_MAX,
			UINT_MAX);
	show_returns(expected, actual);
	null_string = NULL;
	null_pointer = NULL;
	section("null values");
	expected = printf("printf:    string=[%s] pointer=[%p]\n", null_string,
			null_pointer);
	actual = ft_printf("ft_printf: string=[%s] pointer=[%p]\n", null_string,
			null_pointer);
	show_returns(expected, actual);
	printf("ft_printf(NULL) return: %d\n", ft_printf(NULL));
}

int	main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	test_basic_conversions();
	test_integer_limits_and_nulls();
	test_width_and_alignment();
	test_precision_and_flags();
	test_percent_and_characters();
	return (0);
}
