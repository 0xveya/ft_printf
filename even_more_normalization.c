/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   even_more_normalization.c                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 17:52:26 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 17:53:54 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision_disables_zero(t_format *f)
{
	return (f->precision && f->type == conv_int);
}

void	ft_apply_precision_disables_zero(t_format *f)
{
	f->zero = 0;
}

int	ft_hash_invalid_for_type(t_format *f)
{
	return (f->hash && f->type != conv_int && f->type != conv_uint);
}

void	ft_apply_clear_hash(t_format *f)
{
	f->hash = 0;
}
