/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 16:51:42 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:28:06 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_flags(const char *s, int i, t_format *f)
{
	while (ft_is_flag(s[i]))
	{
		if (s[i] == '-')
			f->minus = 1;
		else if (s[i] == '0')
			f->zero = 1;
		else if (s[i] == '#')
			f->hash = 1;
		else if (s[i] == '+')
			f->plus = 1;
		else if (s[i] == ' ')
			f->space = 1;
		i++;
	}
	return (i);
}

static int	ft_parse_width(const char *s, int i, t_format *f)
{
	while (s[i] >= '0' && s[i] <= '9')
	{
		f->width = f->width * 10 + (s[i] - '0');
		i++;
	}
	return (i);
}

static int	ft_parse_precision(const char *s, int i, t_format *f)
{
	if (s[i] == '.')
	{
		f->has_precision = 1;
		f->precision = 0;
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			f->precision = f->precision * 10 + (s[i] - '0');
			i++;
		}
	}
	return (i);
}

static int	ft_parse_type(const char *s, int i, t_format *f)
{
	f->type = ft_char_to_conv(s[i]);
	if (f->type != conv_none)
		i++;
	return (i);
}

int	ft_parse_format(const char *s, int i, t_format *f)
{
	i = ft_parse_flags(s, i, f);
	i = ft_parse_width(s, i, f);
	i = ft_parse_precision(s, i, f);
	i = ft_parse_type(s, i, f);
	return (i);
}
