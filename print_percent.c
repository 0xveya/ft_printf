/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_percent.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:14:39 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:14:43 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent_fmt(t_format *f)
{
	int	count;
	int	pad;

	count = 0;
	pad = f->width - 1;
	if (pad < 0)
		pad = 0;
	if (!f->minus)
		count += ft_putnchar_count(' ', pad);
	count += ft_putnchar_count('%', f->width);
	if (f->minus)
		count += ft_putnchar_count(' ', pad);
	return (count);
}
