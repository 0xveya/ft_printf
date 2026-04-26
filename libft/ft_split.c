/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:04:48 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/24 19:21:21 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delim)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == delim)
			str++;
		if (*str && *str != delim)
		{
			count++;
			while (*str && *str != delim)
				str++;
		}
	}
	return (count);
}

static char	*malloc_word(const char *str, char delim)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != delim)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != delim)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **arr, int used)
{
	while (used > 0)
		free(arr[--used]);
	free(arr);
}

static int	add_word(char **arr, int *i, const char *str, char c)
{
	arr[*i] = malloc_word(str, c);
	if (!arr[*i])
	{
		free_split(arr, *i);
		return (0);
	}
	(*i)++;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	int		word_count;
	char	**arr;
	int		i;

	if (!str)
		return (NULL);
	word_count = count_words(str, c);
	arr = malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			if (!add_word(arr, &i, str, c))
				return (NULL);
			while (*str && *str != c)
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
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

static void	free_split_tester(char **v)
{
	size_t	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
		free(v[i++]);
	free(v);
}

int	main(void)
{
	char	**v;

	v = ft_split("  alpha beta  gamma ", ' ');
	check("ft_split allocates vector for spaced words", v != NULL);
	check("ft_split word 0 == alpha", v && v[0] && strcmp(v[0], "alpha") == 0);
	check("ft_split word 1 == beta", v && v[1] && strcmp(v[1], "beta") == 0);
	check("ft_split word 2 == gamma", v && v[2] && strcmp(v[2], "gamma") == 0);
	check("ft_split vector ends with NULL terminator", v && v[3] == NULL);
	free_split_tester(v);
	v = ft_split(",,,,", ',');
	check("ft_split on only delimiters gives empty vector", v && v[0] == NULL);
	free_split_tester(v);
	print_result();
	return (g_fails != 0);
}
*/
