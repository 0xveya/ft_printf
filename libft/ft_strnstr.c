/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:17:12 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/24 19:25:37 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)str);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] && i + j < n && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
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
	check("ft_strnstr finds world inside hello world", ft_strnstr("hello world",
			"world", 11) != NULL && strcmp(ft_strnstr("hello world", "world",
				11), "world") == 0);
	check("ft_strnstr respects max length and misses world",
		ft_strnstr("hello world", "world", 5) == NULL);
	check("ft_strnstr empty needle returns haystack", ft_strnstr("abc", "",
			3) != NULL && strcmp(ft_strnstr("abc", "", 3), "abc") == 0);
	print_result();
	return (g_fails != 0);
}
*/
