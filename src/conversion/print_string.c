/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_string.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 18:16:02 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:18:57 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_print_str_fmt(t_writer *w, const char *s, t_format *f)
{
	int	len;
	int	pad;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f->has_precision && f->precision < len)
		len = f->precision;
	pad = f->width - len;
	if (pad < 0)
		pad = 0;
	if (!f->minus)
		ft_writer_repeat(w, ' ', (size_t)pad);
	ft_writer_write(w, s, (size_t)len);
	if (f->minus)
		ft_writer_repeat(w, ' ', (size_t)pad);
	return (!w->error);
}
