/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_pointer.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:14:56 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:18:05 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr_fmt(void *ptr, t_format *f)
{
	unsigned long long	address;
	int					count;

	count = 0;
	address = (unsigned long long)ptr;
	if (ptr == NULL)
		return (ft_print_str_fmt("(null)", f));
	count += ft_print_str_fmt("(0x", f);
	return (count += ft_print_uint_fmt(address, f), count);
}
