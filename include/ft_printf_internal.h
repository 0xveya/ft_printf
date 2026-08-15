/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_internal.h                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/25 01:24:51 by sfurst           #+#    #+#              */
/*   Updated: 2026/08/15 23:36:18 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include "ft_printf.h"
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

# define FT_PRINTF_BUFFER_SIZE 4096

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
}			t_conv;

typedef struct s_format
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		has_precision;
	t_conv	type;
}			t_format;

typedef struct s_intfmt
{
	uint64_t	magnitude;
	int			sign;
	int			digits_len;
	int			zeroes;
	int			pad;
}			t_intfmt;

typedef struct s_writer
{
	char	buf[FT_PRINTF_BUFFER_SIZE];
	size_t	len;
	int		total;
	int		error;
}			t_writer;

t_conv		ft_char_to_conv(char c);

int			ft_dispatch_print(t_writer *w, t_format *f, va_list args);

void		ft_format_init(t_format *f);
void		ft_format_normalize(t_format *f);
int			ft_is_flag(char c);
int			ft_parse_format(const char *fmt, int i, t_format *f);

int			ft_writer_char(t_writer *w, char c);
int			ft_writer_flush(t_writer *w);
int			ft_writer_repeat(t_writer *w, char c, size_t n);
int			ft_writer_write(t_writer *w, const char *s, size_t len);

int			ft_print_char_fmt(t_writer *w, int c, t_format *f);
int			ft_print_hex_low_fmt(t_writer *w, unsigned int n, t_format *f);
int			ft_print_hex_up_fmt(t_writer *w, unsigned int n, t_format *f);
int			ft_print_int_fmt(t_writer *w, int n, t_format *f);
int			ft_print_percent_fmt(t_writer *w, t_format *f);
int			ft_print_ptr_fmt(t_writer *w, void *ptr, t_format *f);
int			ft_print_str_fmt(t_writer *w, const char *s, t_format *f);
int			ft_print_uint_fmt(t_writer *w, unsigned int n, t_format *f);

char		*ft_u64_base(char *end, uint64_t n, uint32_t base,
				const char *digits);
char		*ft_u64_dec(char *end, uint64_t n);
char		*ft_u64_pow2(char *end, uint64_t n, uint32_t shift,
				const char *digits);

int			ft_strlen(const char *s) __attribute__((target("avx2")));

void		ft_memcpy(char *dst, const char *src,
				size_t len) __attribute__((target("avx2")));

#endif
