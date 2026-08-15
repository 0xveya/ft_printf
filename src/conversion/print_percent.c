/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_percent.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:14:39 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:34:12 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_print_percent_fmt(t_format *f)
{
	return ((void)f, ft_putchar_count('%'));
}
