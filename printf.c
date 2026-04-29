/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   printf.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/25 01:33:21 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:30:24 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_next(const char *fmt, int *i, va_list args)
{
	t_format	f;

	if (fmt[*i] != '%')
		return (ft_putchar_count(fmt[(*i)++]));
	(*i)++;
	ft_format_init(&f);
	*i = ft_parse_format(fmt, *i, &f);
	ft_format_normalize(&f);
	return (ft_dispatch_print(&f, args));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		written;

	if (!fmt)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		written = ft_print_next(fmt, &i, args);
		if (written < 0)
			return (va_end(args), -1);
		count += written;
	}
	return (va_end(args), count);
}
