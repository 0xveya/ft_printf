/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 20:45:00 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 20:45:00 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ');
}

t_conv	ft_char_to_conv(char c)
{
	if (c == 'c')
		return (conv_char);
	if (c == 's')
		return (conv_str);
	if (c == 'p')
		return (conv_ptr);
	if (c == 'd' || c == 'i')
		return (conv_int);
	if (c == 'u')
		return (conv_uint);
	if (c == 'x')
		return (conv_hex_low);
	if (c == 'X')
		return (conv_hex_up);
	if (c == '%')
		return (conv_percent);
	return (conv_none);
}
