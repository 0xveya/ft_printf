# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/04/23 20:44:50 by sfurst           #+#    #+#               #
#    Updated: 2026/05/03 18:23:31 by sfurst          ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRC_DIR		= .
SRCS		= $(SRC_DIR)/helpers.c \
			  $(SRC_DIR)/helpers2.c \
			  $(SRC_DIR)/main.c \
			  $(SRC_DIR)/normalize.c \
			  $(SRC_DIR)/parse.c \
			  $(SRC_DIR)/parse_utils.c \
			  $(SRC_DIR)/print_char.c \
			  $(SRC_DIR)/print_hex.c \
			  $(SRC_DIR)/print_int.c \
			  $(SRC_DIR)/print_percent.c \
			  $(SRC_DIR)/print_pointer.c \
			  $(SRC_DIR)/print_string.c \
			  $(SRC_DIR)/print_uint.c \
			  $(SRC_DIR)/printf.c \
			  $(SRC_DIR)/printf_dispatch.c


AR		= ar
ARFLAGS		= rcs

OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS)  -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
