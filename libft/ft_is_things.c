/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:41:07 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/24 19:10:53 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
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
	printf("[%d] %s: %s (got=%s want=%s)\n", g_total,
		strcmp(got, want) == 0 ? "ok" : "fail", label, got, want);
}

static void	print_result(void)
{
	printf("fails: %d/%d\n", g_fails, g_total);
}

int	main(void)
{
	int	c;
	int	ok_alpha;
	int	ok_digit;
	int	ok_alnum;
	int	ok_ascii;
	int	ok_print;

	ok_alpha = 1;
	ok_digit = 1;
	ok_alnum = 1;
	ok_ascii = 1;
	ok_print = 1;
	c = -1;
	while (c <= 128)
	{
		ok_alpha &= (!!ft_isalpha(c) == !!isalpha(c));
		ok_digit &= (!!ft_isdigit(c) == !!isdigit(c));
		ok_alnum &= (!!ft_isalnum(c) == !!isalnum(c));
		ok_ascii &= (!!ft_isascii(c) == (c >= 0 && c <= 127));
		ok_print &= (!!ft_isprint(c) == !!isprint(c));
		c++;
	}
	check("ft_isalpha matches isalpha for -1..128", ok_alpha);
	check("ft_isdigit matches isdigit for -1..128", ok_digit);
	check("ft_isalnum matches isalnum for -1..128", ok_alnum);
	check("ft_isascii is true only for 0..127", ok_ascii);
	check("ft_isprint matches isprint for -1..128", ok_print);
	print_result();
	return (g_fails != 0);
}
*/
