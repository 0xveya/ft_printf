/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_uint.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:16:21 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:16:25 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint_fmt(unsigned int n, t_format *f)
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
	count += ft_putnchar_count(n, f->width);
	if (f->minus)
		count += ft_putnchar_count(' ', pad);
	return (count);
}
