/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:14:00 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/24 19:16:34 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (--n && *temp1 == *temp2)
	{
		temp1++;
		temp2++;
	}
	return ((int)*temp1 - *temp2);
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
	unsigned char	a[] = {0, 1, 2, 200, 0};
	unsigned char	b[] = {0, 1, 2, 201, 0};

	check("comparison equal prefix matches libc",
		ft_memcmp(a, b, 3) == memcmp(a, b, 3));
	check("ft_memcmp sign matches memcmp for different byte",
		(ft_memcmp(a, b, 5) < 0) == (memcmp(a, b, 5) < 0));
	check("ft_memcmp with length 0 returns 0", ft_memcmp(a, b, 0) == 0);
	print_result();
	return (g_fails != 0);
}
*/
