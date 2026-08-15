/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_pointer.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:14:56 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:40:05 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <stdint.h>

static int	ft_putstr_count(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (ft_write_count(s, len));
}

int	ft_print_ptr_fmt(void *ptr, t_format *f)
{
	int	count;
	int	written;

	(void)f;
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	count = ft_putstr_count("0x");
	if (count < 0)
		return (-1);
	written = ft_putnbr_base_count((uintptr_t)ptr, "0123456789abcdef");
	if (written < 0)
		return (-1);
	return (count + written);
}
