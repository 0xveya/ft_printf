/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_int.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:14:16 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:44:59 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_numlen_base(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base && ++len)
		n /= base;
	return (len);
}

static void	ft_prepare_intfmt(t_intfmt *v, int n, t_format *f)
{
	v->nb = n;
	v->sign = 0;
	if (v->nb < 0)
		v->sign = '-';
	else if (f->plus)
		v->sign = '+';
	else if (f->space)
		v->sign = ' ';
	if (v->nb < 0)
		v->nb = -v->nb;
	v->digits_len = ft_numlen_base((unsigned long)v->nb, 10);
	if (f->has_precision && f->precision == 0 && v->nb == 0)
		v->digits_len = 0;
	v->zeroes = 0;
	if (f->has_precision && f->precision > v->digits_len)
		v->zeroes = f->precision - v->digits_len;
	v->pad = f->width - v->digits_len - v->zeroes - (v->sign != 0);
	if (v->pad < 0)
		v->pad = 0;
}

static int	ft_write_int_part(int *count, char c, int n)
{
	int	written;

	written = ft_putnchar_count(c, n);
	if (written < 0)
		return (-1);
	*count += written;
	return (0);
}

static int	ft_write_int_body(t_intfmt *v, int *count)
{
	int	written;

	if (v->sign && ft_putchar_count((char)v->sign) < 0)
		return (-1);
	*count += (v->sign != 0);
	if (ft_write_int_part(count, '0', v->zeroes) < 0)
		return (-1);
	if (v->digits_len == 0)
		return (0);
	written = ft_putnbr_base_count((unsigned long)v->nb, "0123456789");
	if (written < 0)
		return (-1);
	*count += written;
	return (0);
}

int	ft_print_int_fmt(int n, t_format *f)
{
	t_intfmt	v;
	int			count;

	ft_prepare_intfmt(&v, n, f);
	count = 0;
	if (!f->minus && f->zero)
	{
		v.zeroes += v.pad;
		v.pad = 0;
	}
	if (!f->minus && ft_write_int_part(&count, ' ', v.pad) < 0)
		return (-1);
	if (ft_write_int_body(&v, &count) < 0)
		return (-1);
	if (f->minus && ft_write_int_part(&count, ' ', v.pad) < 0)
		return (-1);
	return (count);
}
