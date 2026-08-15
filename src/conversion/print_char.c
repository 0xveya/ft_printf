/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_char.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:09:18 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:10:10 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_write_char_pad(int *count, int pad)
{
	int	written;

	written = ft_putnchar_count(' ', pad);
	if (written < 0)
		return (-1);
	*count += written;
	return (0);
}

int	ft_print_char_fmt(int c, t_format *f)
{
	int	count;
	int	pad;

	count = 0;
	pad = f->width - 1;
	if (pad < 0)
		pad = 0;
	if (!f->minus && ft_write_char_pad(&count, pad) < 0)
		return (-1);
	if (ft_putchar_count((char)c) < 0)
		return (-1);
	count++;
	if (f->minus && ft_write_char_pad(&count, pad) < 0)
		return (-1);
	return (count);
}
