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
CPPFLAGS	= -Iinclude -MMD -MP
RM			= rm -f

JOBS		?= $(shell nproc)
MAKEFLAGS	+= -j $(JOBS) -l $(JOBS)

SRC_DIR		= src
OBJ_DIR		= obj
SRCS		= $(SRC_DIR)/conversion/print_char.c \
			  $(SRC_DIR)/conversion/print_hex.c \
			  $(SRC_DIR)/conversion/print_int.c \
			  $(SRC_DIR)/conversion/print_percent.c \
			  $(SRC_DIR)/conversion/print_pointer.c \
			  $(SRC_DIR)/conversion/print_string.c \
			  $(SRC_DIR)/conversion/print_uint.c \
			  $(SRC_DIR)/core/printf.c \
			  $(SRC_DIR)/core/printf_dispatch.c \
			  $(SRC_DIR)/format/normalize.c \
			  $(SRC_DIR)/format/parse.c \
			  $(SRC_DIR)/format/parse_utils.c \
			  $(SRC_DIR)/support/helpers.c \
			  $(SRC_DIR)/support/helpers2.c


AR		= ar
ARFLAGS		= rcs

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(RM) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

compiledb:
	$(MAKE) fclean
	compiledb -n make

-include $(DEPS)

.PHONY: all bonus clean compiledb fclean re
.DEFAULT_GOAL := all
