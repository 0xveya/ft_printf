/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:19:58 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/24 19:17:44 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;

	dest_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while (len--)
			dest_char[len] = src_char[len];
	else
		while (len--)
			*dest_char++ = *src_char++;
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
	printf("[%d] %s: %s (got=%s want=%s)\n", g_total, strcmp(got,
			want) == 0 ? "ok" : "fail", label, got, want);
}

static void	print_result(void)
{
	printf("fails: %d/%d\n", g_fails, g_total);
}

int	main(void)
{
	char	a[16] = "0123456789";
	char	b[16] = "0123456789";

	check("function returns destination pointer", ft_memmove(a + 2, a, 8) == a
		+ 2);
	memmove(b + 2, b, 8);
	check("ft_memmove handles forward overlap like memmove", memcmp(a, b,
			sizeof(a)) == 0);
	ft_memmove(a, a + 2, 4);
	memmove(b, b + 2, 4);
	check("ft_memmove handles backward overlap like memmove", memcmp(a, b,
			sizeof(a)) == 0);
	print_result();
	return (g_fails != 0);
}
*/
