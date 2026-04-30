/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/25 01:24:51 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/26 18:48:42 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

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

typedef struct s_intfmt
{
	long		nb;
	int			sign;
	int			digits_len;
	int			zeroes;
	int			pad;
}				t_intfmt;

t_conv			ft_char_to_conv(char c);
int				ft_dispatch_print(t_format *f, va_list args);
void			ft_format_init(t_format *f);
void			ft_format_normalize(t_format *f);
int				ft_is_flag(char c);
int				ft_parse_format(const char *fmt, int i, t_format *f);
int				ft_printf(const char *format, ...);
int				ft_write_count(char *s, int len);
int				ft_putchar_count(char c);
int				ft_putnchar_count(char c, int n);

int				ft_print_char_fmt(int c, t_format *f);
int				ft_print_hex_low_fmt(unsigned int n, t_format *f);
int				ft_print_hex_up_fmt(unsigned int n, t_format *f);
int				ft_print_int_fmt(int n, t_format *f);
int				ft_print_percent_fmt(t_format *f);
int				ft_print_ptr_fmt(void *ptr, t_format *f);
int				ft_print_str_fmt(char *s, t_format *f);
int				ft_print_uint_fmt(unsigned int n, t_format *f);
int				ft_putnbr_base_count(unsigned long n, char *base);

int				ft_strlen(char *s);

#endif
