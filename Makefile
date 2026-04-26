# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/04/23 20:44:50 by sfurst           #+#    #+#               #
#    Updated: 2026/04/26 18:19:58 by sfurst          ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRC_DIR		= .
SRCS		= $(SRC_DIR)/even_even_more_normalization.c \
			  $(SRC_DIR)/even_more_normalization.c \
			  $(SRC_DIR)/format_parser.c \
			  $(SRC_DIR)/helpers.c \
			  $(SRC_DIR)/more_normalization.c \
			  $(SRC_DIR)/normalize.c \
			  $(SRC_DIR)/parse.c \
			  $(SRC_DIR)/print_char.c \
			  $(SRC_DIR)/print_hex.c \
			  $(SRC_DIR)/print_int.c \
			  $(SRC_DIR)/print_percent.c \
			  $(SRC_DIR)/print_pointer.c \
			  $(SRC_DIR)/print_string.c \
			  $(SRC_DIR)/print_uint.c \
			  $(SRC_DIR)/printf.c \
			  $(SRC_DIR)/printf_dispatch.c \
			  $(SRC_DIR)/testingshit.c

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

AR		= ar
ARFLAGS		= rcs

OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
