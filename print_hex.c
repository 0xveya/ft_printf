/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_hex.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:13:39 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:51:52 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_count(char *s)
{
	int	len;

	return (len = ft_strlen(s), write(1, s, len), len);
}

int	ft_print_hex_low_fmt(unsigned int n, t_format *f)
{
	int	count;

	count = 0;
	if (f->hash && n != 0)
		count += ft_putstr_count("0x");
	return (count += ft_putnbr_base_count(n, "0123456789abcdef"), count);
}

int	ft_print_hex_up_fmt(unsigned int n, t_format *f)
{
	int	count;

	count = 0;
	if (f->hash && n != 0)
		count += ft_putstr_count("0X");
	return (count += ft_putnbr_base_count(n, "0123456789ABCDEF"), count);
}
