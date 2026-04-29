/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 16:45:56 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:12:49 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_count(char *s, int len)
{
	if (write(1, s, len) != len)
		return (-1);
	return (len);
}

int	ft_putchar_count(char c)
{
	return (ft_write_count(&c, 1));
}

int	ft_putnchar_count(char c, int n)
{
	int	i;
	int	count;
	int	written;

	i = 0;
	count = 0;
	while (i < n)
	{
		written = ft_putchar_count(c);
		if (written < 0)
			return (-1);
		count += written;
		i++;
	}
	return (count);
}

void	ft_format_init(t_format *f)
{
	f->minus = 0;
	f->zero = 0;
	f->hash = 0;
	f->plus = 0;
	f->space = 0;
	f->width = 0;
	f->precision = 0;
	f->has_precision = 0;
	f->type = conv_none;
}
