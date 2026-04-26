/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:38 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/24 19:23:20 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(s1_len + s2_len + 1);
	if (!ptr)
		return (NULL);
	if (s1_len > 0)
		ft_memcpy(ptr, s1, s1_len);
	if (s2_len > 0)
		ft_memcpy(ptr + s1_len, s2, s2_len);
	return (ptr[s1_len + s2_len] = '\0', ptr);
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
	char	*s;

	s = ft_strjoin("hello", " world");
	check("ft_strjoin allocates joined string", s != NULL);
	if (s)
		check_str_case("ft_strjoin(\"hello\", \" world\")", s, "hello world");
	free(s);
	s = ft_strjoin("", "world");
	check("ft_strjoin handles empty left string", s != NULL);
	if (s)
		check_str_case("ft_strjoin(\"\", \"world\")", s, "world");
	free(s);
	s = ft_strjoin("hello", "");
	check("ft_strjoin handles empty right string", s != NULL);
	if (s)
		check_str_case("ft_strjoin(\"hello\", \"\")", s, "hello");
	free(s);
	s = ft_strjoin("", "");
	check("ft_strjoin handles two empty strings", s != NULL);
	if (s)
		check_str_case("ft_strjoin(\"\", \"\")", s, "");
	free(s);
	print_result();
	return (g_fails != 0);
}
*/
