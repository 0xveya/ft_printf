/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_uint.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:16:21 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:39:05 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_print_uint_fmt(unsigned int n, t_format *f)
{
	return ((void)f, ft_putnbr_base_count(n, "0123456789"));
}
