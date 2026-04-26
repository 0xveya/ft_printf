# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfurst <sfurst@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 12:40:44 by sfurst            #+#    #+#              #
#    Updated: 2026/04/24 18:26:18 by sfurst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MMD -MP
RM		= rm -f

SRC_DIR		= .
SRCS		= $(SRC_DIR)/ft_atoi.c \
			  $(SRC_DIR)/ft_bzero.c \
			  $(SRC_DIR)/ft_calloc.c \
			  $(SRC_DIR)/ft_is_things.c \
			  $(SRC_DIR)/ft_itoa.c \
			  $(SRC_DIR)/ft_lstadd_back.c \
			  $(SRC_DIR)/ft_lstadd_front.c \
			  $(SRC_DIR)/ft_lstclear.c \
			  $(SRC_DIR)/ft_lstdelone.c \
			  $(SRC_DIR)/ft_lstiter.c \
			  $(SRC_DIR)/ft_lstlast.c \
			  $(SRC_DIR)/ft_lstmap.c \
			  $(SRC_DIR)/ft_lstnew.c \
			  $(SRC_DIR)/ft_lstsize.c \
			  $(SRC_DIR)/ft_memchr.c \
			  $(SRC_DIR)/ft_memcmp.c \
			  $(SRC_DIR)/ft_memcpy.c \
			  $(SRC_DIR)/ft_memmove.c \
			  $(SRC_DIR)/ft_memset.c \
			  $(SRC_DIR)/ft_putchar_fd.c \
			  $(SRC_DIR)/ft_putendl_fd.c \
			  $(SRC_DIR)/ft_putnbr_fd.c \
			  $(SRC_DIR)/ft_putstr_fd.c \
			  $(SRC_DIR)/ft_split.c \
			  $(SRC_DIR)/ft_strchr.c \
			  $(SRC_DIR)/ft_strdup.c \
			  $(SRC_DIR)/ft_striteri.c \
			  $(SRC_DIR)/ft_strjoin.c \
			  $(SRC_DIR)/ft_strlcat.c \
			  $(SRC_DIR)/ft_strlcpy.c \
			  $(SRC_DIR)/ft_strlen.c \
			  $(SRC_DIR)/ft_strmapi.c \
			  $(SRC_DIR)/ft_strncmp.c \
			  $(SRC_DIR)/ft_strnstr.c \
			  $(SRC_DIR)/ft_strrchr.c \
			  $(SRC_DIR)/ft_strtrim.c \
			  $(SRC_DIR)/ft_substr.c \
			  $(SRC_DIR)/ft_to_upper_to_lower.c

OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)

AR		= ar
ARFLAGS		= rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
