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

int	ft_print_ptr_fmt(t_writer *w, void *ptr, t_format *f)
{
	(void)f;
	if (!ptr)
		return (ft_writer_write(w, "(nil)", 5));
	ft_writer_write(w, "0x", 2);
	ft_putnbr_base_writer(w, (uintptr_t)ptr, "0123456789abcdef");
	return (!w->error);
}
