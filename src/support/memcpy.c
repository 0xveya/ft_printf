/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   memcpy.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/15 23:32:22 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/15 23:32:23 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstc;
	const unsigned char	*srcc;

	dstc = (unsigned char *)dst;
	srcc = (const unsigned char *)src;
	while (n--)
		*dstc++ = *srcc++;
	return (dst);
}
