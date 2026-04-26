/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   even_even_more_normalization.c                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 17:54:21 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:33:13 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sign_flags_invalid_for_type(t_format *f)
{
	return ((f->plus || f->space) && f->type != conv_int);
}

void	ft_apply_clear_sign_flags(t_format *f)
{
	f->plus = 0;
	f->space = 0;
}

int	ft_width_negative(t_format *f)
{
	return (f->width < 0);
}

void	ft_apply_negative_width_rule(t_format *f)
{
	f->width = 0;
}
