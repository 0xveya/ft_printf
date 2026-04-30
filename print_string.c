/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_string.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:16:02 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:18:57 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_str_pad(int *count, int pad)
{
	int	written;

	written = ft_putnchar_count(' ', pad);
	if (written < 0)
		return (-1);
	*count += written;
	return (0);
}

static int	ft_putnstr_count(char *s, int n)
{
	int	count;
	int	written;

	count = 0;
	while (s[count] && count < n)
	{
		written = ft_putchar_count(s[count]);
		if (written < 0)
			return (-1);
		count += written;
	}
	return (count);
}

int	ft_print_str_fmt(char *s, t_format *f)
{
	int	count;
	int	len;
	int	pad;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f->has_precision && f->precision < len)
		len = f->precision;
	pad = f->width - len;
	if (pad < 0)
		pad = 0;
	count = 0;
	if (!f->minus && ft_write_str_pad(&count, pad) < 0)
		return (-1);
	len = ft_putnstr_count(s, len);
	if (len < 0)
		return (-1);
	count += len;
	if (f->minus && ft_write_str_pad(&count, pad) < 0)
		return (-1);
	return (count);
}
