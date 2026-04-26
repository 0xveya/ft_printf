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

#include "ft_printf.h"

static int	ft_numlen_base(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base && ++len)
		n /= base;
	return (len);
}

static int	ft_int_sign(long nb, t_format *f)
{
	if (nb < 0)
		return ('-');
	if (f->plus)
		return ('+');
	if (f->space)
		return (' ');
	return (0);
}

int	ft_putnbr_base_count(unsigned long n, char *base)
{
	int				count;
	unsigned long	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		count += ft_putnbr_base_count(n / base_len, base);
	return (count += ft_putchar_count(base[n % base_len]), count);
}

static void	ft_prepare_intfmt(t_intfmt *v, int n, t_format *f)
{
	v->nb = n;
	v->sign = ft_int_sign(v->nb, f);
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

int	ft_print_int_fmt(int n, t_format *f)
{
	t_intfmt	v;
	int			count;

	ft_prepare_intfmt(&v, n, f);
	count = 0;
	if (!f->minus && !f->zero)
		count += ft_putnchar_count(' ', v.pad);
	if (v.sign)
		count += ft_putchar_count((char)v.sign);
	if (!f->minus && f->zero)
		count += ft_putnchar_count('0', v.pad);
	count += ft_putnchar_count('0', v.zeroes);
	if (v.digits_len > 0)
		count += ft_putnbr_base_count((unsigned long)v.nb, "0123456789");
	if (f->minus)
		count += ft_putnchar_count(' ', v.pad);
	return (count);
}
