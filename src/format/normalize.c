/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   normalize.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 16:52:34 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 17:56:15 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	ft_format_normalize(t_format *f)
{
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	if (f->has_precision && (f->type == conv_int || f->type == conv_uint
			|| f->type == conv_hex_low || f->type == conv_hex_up))
		f->zero = 0;
	if (f->type != conv_hex_low && f->type != conv_hex_up)
		f->hash = 0;
	if (f->type != conv_int)
	{
		f->plus = 0;
		f->space = 0;
	}
}
