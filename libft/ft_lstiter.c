/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:13:22 by sfurst            #+#    #+#             */
/*   Updated: 2026/04/21 20:22:02 by sfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
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

static void	upper_content(void *p)
{
	char	*s;

	s = p;
	if (s && s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;
}

static void	*dup_content(void *p)
{
	return (ft_strdup((char *)p));
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*mapped;

	a = ft_lstnew(ft_strdup("one"));
	b = ft_lstnew(ft_strdup("two"));
	c = ft_lstnew(ft_strdup("three"));
	check("ft_lstnew stores duplicated content pointer",
		a && strcmp(a->content, "one") == 0);
	ft_lstadd_back(&a, b);
	ft_lstadd_front(&a, c);
	check("ft_lstadd_front/back create a 3-node list", ft_lstsize(a) == 3);
	check("ft_lstlast returns the final node", ft_lstlast(a) == b);
	ft_lstiter(a, upper_content);
	check("ft_lstiter applies callback to list content",
		strcmp(c->content, "Three") == 0);
	mapped = ft_lstmap(a, dup_content, free);
	check("ft_lstmap duplicates each node into a new list",
		mapped && ft_lstsize(mapped) == 3);
	ft_lstclear(&mapped, free);
	check("ft_lstclear frees mapped list and sets pointer NULL",
		mapped == NULL);
	ft_lstclear(&a, free);
	check("ft_lstclear frees original list and sets pointer NULL", a == NULL);
	print_result();
	return (g_fails != 0);
}
*/
