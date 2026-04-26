/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   testingshit.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:20:27 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:25:10 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 4096

typedef struct s_cap
{
	int		old_fd;
	int		pipe_fd[2];
	char	buf[BUF_SIZE];
}			t_cap;

static void	cap_start(t_cap *c)
{
	fflush(stdout);
	pipe(c->pipe_fd);
	c->old_fd = dup(STDOUT_FILENO);
	dup2(c->pipe_fd[1], STDOUT_FILENO);
	close(c->pipe_fd[1]);
}

static void	cap_end(t_cap *c)
{
	ssize_t	n;

	fflush(stdout);
	dup2(c->old_fd, STDOUT_FILENO);
	close(c->old_fd);
	n = read(c->pipe_fd[0], c->buf, BUF_SIZE - 1);
	if (n < 0)
		n = 0;
	c->buf[n] = '\0';
	close(c->pipe_fd[0]);
}

static void	print_result(const char *type, const char *label, const char *fmt,
		const char *p_out, int p_ret, const char *f_out, int f_ret)
{
	printf("\n[%-8s] %s\n", type, label);
	printf("fmt       : \"%s\"\n", fmt);
	printf("printf    : >%-25s< ret=%d\n", p_out, p_ret);
	printf("ft_printf : >%-25s< ret=%d\n", f_out, f_ret);
}

static void	test_char(const char *label, const char *fmt, int c)
{
	t_cap	p;
	t_cap	f;
	int		a;
	int		b;

	cap_start(&p);
	a = printf(fmt, c);
	cap_end(&p);
	cap_start(&f);
	b = ft_printf(fmt, c);
	cap_end(&f);
	print_result("CHAR", label, fmt, p.buf, a, f.buf, b);
}

static void	test_str(const char *label, const char *fmt, char *s)
{
	t_cap	p;
	t_cap	f;
	int		a;
	int		b;

	cap_start(&p);
	a = printf(fmt, s);
	cap_end(&p);
	cap_start(&f);
	b = ft_printf(fmt, s);
	cap_end(&f);
	print_result("STR", label, fmt, p.buf, a, f.buf, b);
}

static void	test_int(const char *label, const char *fmt, int n)
{
	t_cap	p;
	t_cap	f;
	int		a;
	int		b;

	cap_start(&p);
	a = printf(fmt, n);
	cap_end(&p);
	cap_start(&f);
	b = ft_printf(fmt, n);
	cap_end(&f);
	print_result("INT", label, fmt, p.buf, a, f.buf, b);
}

static void	test_uint(const char *label, const char *fmt, unsigned int n)
{
	t_cap	p;
	t_cap	f;
	int		a;
	int		b;

	cap_start(&p);
	a = printf(fmt, n);
	cap_end(&p);
	cap_start(&f);
	b = ft_printf(fmt, n);
	cap_end(&f);
	print_result("UINT/HEX", label, fmt, p.buf, a, f.buf, b);
}

static void	test_ptr(const char *label, const char *fmt, void *pnt)
{
	t_cap	p;
	t_cap	f;
	int		a;
	int		b;

	cap_start(&p);
	a = printf(fmt, pnt);
	cap_end(&p);
	cap_start(&f);
	b = ft_printf(fmt, pnt);
	cap_end(&f);
	print_result("PTR", label, fmt, p.buf, a, f.buf, b);
}

static void	test_percent(const char *label, const char *fmt)
{
	t_cap	p;
	t_cap	f;
	int		a;
	int		b;

	cap_start(&p);
	a = printf(fmt);
	cap_end(&p);
	cap_start(&f);
	b = ft_printf(fmt);
	cap_end(&f);
	print_result("PERCENT", label, fmt, p.buf, a, f.buf, b);
}

int	main(void)
{
	int	x;

	x = 42;
	test_char("basic", "|%c|", 'A');
	test_char("width", "|%5c|", 'A');
	test_char("minus width", "|%-5c|", 'A');
	test_str("basic", "|%s|", "hello");
	test_str("width", "|%10s|", "hello");
	test_str("minus width", "|%-10s|", "hello");
	test_str("precision", "|%.3s|", "hello");
	test_str("width precision", "|%10.3s|", "hello");
	test_str("minus width precision", "|%-10.3s|", "hello");
	test_str("null", "|%s|", NULL);
	test_int("basic", "|%d|", 42);
	test_int("negative", "|%d|", -42);
	test_int("width", "|%8d|", 42);
	test_int("minus width", "|%-8d|", 42);
	test_int("zero width", "|%08d|", 42);
	test_int("precision", "|%.5d|", 42);
	test_int("width precision", "|%8.5d|", 42);
	test_int("plus", "|%+d|", 42);
	test_int("space", "|% d|", 42);
	test_int("zero precision", "|%.0d|", 0);
	test_uint("unsigned", "|%u|", 4294967295u);
	test_uint("hex low", "|%x|", 255);
	test_uint("hex up", "|%X|", 255);
	test_uint("hash low", "|%#x|", 255);
	test_uint("hash up", "|%#X|", 255);
	test_uint("hash zero", "|%#x|", 0);
	test_ptr("pointer", "|%p|", &x);
	test_ptr("null pointer", "|%p|", NULL);
	test_percent("basic", "|%%|");
	test_percent("width", "|%5%|");
	test_percent("minus width", "|%-5%|");
	return (0);
}
