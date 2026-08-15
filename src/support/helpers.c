/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 16:45:56 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/30 21:52:15 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	ft_format_init(t_format *f)
{
	f->minus = 0;
	f->zero = 0;
	f->hash = 0;
	f->plus = 0;
	f->space = 0;
	f->width = 0;
	f->precision = 0;
	f->has_precision = 0;
	f->type = conv_none;
}
