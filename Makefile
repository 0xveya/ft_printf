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
TEST_NAME	= ft_printf_test

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude -MMD -MP
RM			= rm -f

JOBS		?= $(shell nproc)
MAKEFLAGS	+= -j $(JOBS) -l $(JOBS)

SRC_DIR		= src
OBJ_DIR		= obj
TEST_OBJ_DIR	= obj_test
SRCS		= $(SRC_DIR)/conversion/print_char.c \
			  $(SRC_DIR)/conversion/integer_digits.c \
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
			  $(SRC_DIR)/support/memcpy.c \
			  $(SRC_DIR)/support/strlen.c \
			  $(SRC_DIR)/support/writer.c


AR		= ar
ARFLAGS		= rcs

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)
TEST_OBJS	= $(SRCS:$(SRC_DIR)/%.c=$(TEST_OBJ_DIR)/%.o)
TEST_DEPS	= $(TEST_OBJS:.o=.d)

all: $(NAME)

bonus: $(NAME)

test: $(TEST_NAME)
	./$(TEST_NAME)

$(NAME): $(OBJS)
	$(RM) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TEST_NAME): $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o $@

$(TEST_OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -DFT_PRINTF_TEST -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR) $(TEST_OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

compiledb:
	$(MAKE) fclean
	compiledb -n make

-include $(DEPS) $(TEST_DEPS)

.PHONY: all bonus clean compiledb fclean re test
.DEFAULT_GOAL := all
