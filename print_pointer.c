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

#include "ft_printf.h"
#include <stdint.h>

int	ft_putstr_count(char *s)
{
	int	len;

	return (len = ft_strlen(s), write(1, s, len), len);
}

int	ft_print_ptr_fmt(void *ptr, t_format *f)
{
	int	count;

	(void)f;
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	count = 0;
	count += ft_putstr_count("0x");
	count += ft_putnbr_base_count((uintptr_t)ptr, "0123456789abcdef");
	return (count);
}
