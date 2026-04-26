/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   printf.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/25 01:33:21 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 16:50:54 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_format	f;
	int			i;
	int			count;

	if (!fmt)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
			count += ft_putchar_count(fmt[i++]);
		else
		{
			i++;
			ft_format_init(&f);
			i = ft_parse_format(fmt, i, &f);
			ft_format_normalize(&f);
			count += ft_dispatch_print(&f, &args);
		}
	}
	return (va_end(args), count);
}
