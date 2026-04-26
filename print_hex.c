/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_hex.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:13:39 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:13:50 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_low_fmt(unsigned int n, t_format *f)
{
	int	count;
	int	pad;

	count = 0;
	pad = f->width - 1;
	if (pad < 0)
		pad = 0;
	if (!f->minus)
		count += ft_putnchar_count(' ', pad);
	count += ft_putnchar_count('0', f->zero);
	count += ft_putnchar_count('x', f->hash);
	count += ft_putnchar_count('0', f->zero);
	count += ft_putnchar_count(n, f->width);
	if (f->minus)
		count += ft_putnchar_count(' ', pad);
	return (count);
}

int	ft_print_hex_up_fmt(unsigned int n, t_format *f)
{
	int	count;
	int	pad;

	count = 0;
	pad = f->width - 1;
	if (pad < 0)
		pad = 0;
	if (!f->minus)
		count += ft_putnchar_count(' ', pad);
	count += ft_putnchar_count('0', f->zero);
	count += ft_putnchar_count('X', f->hash);
	count += ft_putnchar_count('0', f->zero);
	count += ft_putnchar_count(n, f->width);
	if (f->minus)
		count += ft_putnchar_count(' ', pad);
	return (count);
}
