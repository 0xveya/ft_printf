/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers2.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:48:24 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/15 23:23:21 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_putnbr_base_writer(t_writer *w, unsigned long n, const char *base)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		if (!ft_putnbr_base_writer(w, n / base_len, base))
			return (0);
	return (ft_writer_char(w, base[n % base_len]));
}
