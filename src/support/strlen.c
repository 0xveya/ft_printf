/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   strlen.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/15 23:32:29 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/15 23:40:03 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <immintrin.h>
#include <stdint.h>

int	ft_strlen(const char *s)
{
	const char		*p;
	__m256i			zero;
	__m256i			v;
	unsigned int	mask;

	p = s;
	while (((uintptr_t)p & 31) != 0)
	{
		if (*p == '\0')
			return ((int)(p - s));
		p++;
	}
	zero = _mm256_setzero_si256();
	while (1)
	{
		v = _mm256_load_si256((const __m256i *)p);
		mask = (unsigned int)_mm256_movemask_epi8(_mm256_cmpeq_epi8(v, zero));
		if (mask != 0)
			return ((int)(p - s) + __builtin_ctz(mask));
		p += 32;
	}
}
