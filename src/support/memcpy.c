/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   memcpy.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/15 23:32:22 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/15 23:34:54 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <immintrin.h>

void	ft_memcpy(char *dst, const char *src, size_t len)
{
	while (len >= 32)
	{
		_mm256_storeu_si256((__m256i *)(dst),
			_mm256_loadu_si256((const __m256i *)(src)));
		dst += 32;
		src += 32;
		len -= 32;
	}
	while (len-- > 0)
		*dst++ = *src++;
}
