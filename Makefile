# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/23 20:44:50 by sfurst            #+#    #+#              #
#    Updated: 2026/04/25 18:08:12 by sfurst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRC_DIR		= .
SRCS		= $(SRC_DIR)/format_parser.c \
			  $(SRC_DIR)/helpers.c \
			  $(SRC_DIR)/printf.c

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
