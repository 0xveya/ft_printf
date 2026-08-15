/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   printf_dispatch.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 17:00:28 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:06:49 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_dispatch_print(t_format *f, va_list args)
{
	if (f->type == conv_char)
		return (ft_print_char_fmt(va_arg(args, int), f));
	if (f->type == conv_str)
		return ((ft_print_str_fmt(va_arg(args, char *), f)));
	if (f->type == conv_ptr)
		return ((ft_print_ptr_fmt(va_arg(args, void *), f)));
	if (f->type == conv_int)
		return (ft_print_int_fmt(va_arg(args, int), f));
	if (f->type == conv_uint)
		return ((ft_print_uint_fmt(va_arg(args, unsigned int), f)));
	if (f->type == conv_hex_low)
		return ((ft_print_hex_low_fmt(va_arg(args, unsigned int), f)));
	if (f->type == conv_hex_up)
		return ((ft_print_hex_up_fmt(va_arg(args, unsigned int), f)));
	if (f->type == conv_percent)
		return (ft_print_percent_fmt(f));
	return (0);
}
