/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/25 01:24:51 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:13:22 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef enum e_conv
{
	conv_none,
	conv_char,
	conv_str,
	conv_ptr,
	conv_int,
	conv_uint,
	conv_hex_low,
	conv_hex_up,
	conv_percent
}				t_conv;

typedef struct s_format
{
	int			minus;
	int			zero;
	int			hash;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			has_precision;
	t_conv		type;
}				t_format;

typedef int		(*t_print_fn)(t_format *f, va_list *args);

typedef struct s_dispatch
{
	t_conv		type;
	t_print_fn	fn;
}				t_dispatch;

void			ft_apply_clear_hash(t_format *f);
void			ft_apply_clear_sign_flags(t_format *f);
void			ft_apply_minus_overrides_zero(t_format *f);
void			ft_apply_negative_width_rule(t_format *f);
void			ft_apply_plus_overrides_space(t_format *f);
void			ft_apply_precision_disables_zero(t_format *f);
t_conv			ft_char_to_conv(char c);
int				ft_dispatch_print(t_format *f, va_list args);
int				ft_flag_minus_overrides_zero(t_format *f);
int				ft_flag_plus_overrides_space(t_format *f);
void			ft_format_init(t_format *f);
void			ft_format_normalize(t_format *f);
int				ft_hash_invalid_for_type(t_format *f);
int				ft_is_flag(char c);
int				ft_parse_format(const char *fmt, int i, t_format *f);
int				ft_precision_disables_zero(t_format *f);
int				ft_printf(const char *format, ...);
int				ft_putchar_count(char c);
int				ft_putnchar_count(char c, int n);
int				ft_sign_flags_invalid_for_type(t_format *f);
int				ft_width_negative(t_format *f);

int				ft_print_char_fmt(int c, t_format *f);
int				ft_print_hex_low_fmt(unsigned int n, t_format *f);
int				ft_print_hex_up_fmt(unsigned int n, t_format *f);
int				ft_print_int_fmt(int n, t_format *f);
int				ft_print_percent_fmt(t_format *f);
int				ft_print_ptr_fmt(void *ptr, t_format *f);
int				ft_print_str_fmt(char *s, t_format *f);
int				ft_print_uint_fmt(unsigned int n, t_format *f);

#endif
