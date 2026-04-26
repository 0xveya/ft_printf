/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:18:54 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/24 19:16:59 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstc;
	unsigned char	*srcc;

	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (n--)
		*dstc++ = *srcc++;
	return (dst);
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
	char	dst[16];
	char	ref[16];

	memset(dst, 'x', sizeof(dst));
	memset(ref, 'x', sizeof(ref));
	check("function returns destination pointer",
		ft_memcpy(dst, "hello", 6) == dst);
	memcpy(ref, "hello", 6);
	check("ft_memcpy copies bytes like memcpy",
		memcmp(dst, ref, sizeof(dst)) == 0);
	ft_memcpy(dst, "zz", 0);
	check("zero-length call leaves buffer unchanged",
		memcmp(dst, ref, sizeof(dst)) == 0);
	print_result();
	return (g_fails != 0);
}
*/
