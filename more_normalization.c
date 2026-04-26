/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   more_normalization.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 17:46:40 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 17:50:03 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_minus_overrides_zero(t_format *f)
{
	return (f->minus && f->zero);
}

void	ft_apply_minus_overrides_zero(t_format *f)
{
	f->zero = 0;
}

int	ft_flag_plus_overrides_space(t_format *f)
{
	return (f->plus && f->space);
}

void	ft_apply_plus_overrides_space(t_format *f)
{
	f->space = 0;
}
