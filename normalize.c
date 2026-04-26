/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   normalize.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 16:52:34 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 17:56:15 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision_negative(t_format *f)
{
	return (f->precision < 0);
}

void	ft_apply_negative_precision_rule(t_format *f)
{
	f->precision = 0;
}

void	ft_format_normalize(t_format *f)
{
	if (ft_flag_minus_overrides_zero(f))
		ft_apply_minus_overrides_zero(f);
	if (ft_flag_plus_overrides_space(f))
		ft_apply_plus_overrides_space(f);
	if (ft_precision_disables_zero(f))
		ft_apply_precision_disables_zero(f);
	if (ft_hash_invalid_for_type(f))
		ft_apply_clear_hash(f);
	if (ft_sign_flags_invalid_for_type(f))
		ft_apply_clear_sign_flags(f);
	if (ft_width_negative(f))
		ft_apply_negative_width_rule(f);
	if (ft_precision_negative(f))
		ft_apply_negative_precision_rule(f);
}
