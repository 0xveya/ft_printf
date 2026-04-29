/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers2.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:48:24 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:48:32 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while ((s[len]) && (len++, 1))
		;
	return (len);
}

int	ft_putnbr_base_count(unsigned long n, char *base)
{
	int				count;
	int				written;
	unsigned long	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		count = ft_putnbr_base_count(n / base_len, base);
		if (count < 0)
			return (-1);
	}
	written = ft_putchar_count(base[n % base_len]);
	if (written < 0)
		return (-1);
	return (count + written);
}
