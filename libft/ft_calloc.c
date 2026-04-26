/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:34:33 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/24 19:10:25 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	total;

	if (n != 0 && size > SIZE_MAX / n)
		return (NULL);
	total = n * size;
	if (total == 0)
		total = 1;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	return (ft_bzero(ptr, total), ptr);
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

 static void	check_str_case(const char *label, const char *got,
		const char *want)
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
		unsigned char	*p;
		unsigned char	*ref;
		size_t			i;
		int				zeroed;

		p = ft_calloc(8, sizeof(unsigned char));
		ref = calloc(8, sizeof(unsigned char));
		check("ft_calloc(8, sizeof(unsigned char)) returns memory", p != NULL
			&& ref != NULL);
		zeroed = 1;
		i = 0;
		while (p && ref && i < 8)
			zeroed &= (p[i] == ref[i], p[i++] == 0);
		check("ft_calloc matches calloc zeroed bytes", zeroed);
		free(p);
		free(ref);
		p = ft_calloc(0, 8);
		check("ft_calloc(0, 8) returns safely", p != NULL || p == NULL);
		free(p);
		p = ft_calloc((size_t)-1, 2);
		check("ft_calloc((size_t)-1, 2) returns NULL on overflow", p == NULL);
		print_result();
		return (g_fails != 0);
 }
 */
