/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:20:50 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/25 01:44:38 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *s)
{
	long	result;
	int		sign;
	int		digit;

	sign = 1;
	result = 0;
	while ((ft_is_space(*s)) && (s++, 1))
		;
	if (*s == '-' || *s == '+')
		sign = 44 - *s++;
	while (*s >= '0' && *s <= '9')
	{
		digit = *s++ - '0';
		if ((sign > 0 && result > (LONG_MAX - digit) / 10) || (sign < 0
				&& result < (LONG_MIN + digit) / 10))
			return (-1 + (sign < 0));
		result = result * 10 + digit * sign;
	}
	return ((int)result);
}
/*
#include "libft.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	g_fails;
static int	g_total;

static void	check(const char *label, int ok)
{
	g_total++;
	if (!ok)
		g_fails++;
	printf("[%d] %s: %s\n", g_total, ok ? "ok" : "fail", label);
}

static void	check_int_case(const char *label, long got, long want)
{
	g_total++;
	if (got != want)
		g_fails++;
	printf("[%d] %s: %s (got=%ld want=%ld)\n", g_total,
		got == want ? "ok" : "fail", label, got, want);
}

static void	check_str_case(const char *label, const char *got, const char *want)
{
	g_total++;
	if (strcmp(got, want) != 0)
		g_fails++;
	printf("[%d] %s: %s (got=%s want=%s)\n", g_total, strcmp(got,
			want) == 0 ? "ok" : "fail", label, got, want);
}

static void	print_result(void)
{
	printf("fails: %d/%d\n", g_fails, g_total);
}

int	main(void)
{
	check_int_case("ft_atoi(\"42\")", ft_atoi("42"), atoi("42"));
	check_int_case("ft_atoi(\" \\t\\n\\r\\v\\f-123x\")",
		ft_atoi(" \t\n\r\v\f-123x"), atoi(" \t\n\r\v\f-123x"));
	check_int_case("ft_atoi(\"+17\")", ft_atoi("+17"), atoi("+17"));
	check_int_case("ft_atoi(\"--12\")", ft_atoi("--12"), atoi("--12"));
	check_int_case("ft_atoi(\"0\")", ft_atoi("0"), atoi("0"));
	check_int_case("ft_atoi(\"2147483648\")", ft_atoi("2147483648"),
		atoi("2147483648"));
	check_int_case("ft_atoi(\"9223372036854775808\")",
		ft_atoi("9223372036854775808"), atoi("9223372036854775808"));
	print_result();
	return (g_fails != 0);
}
*/
