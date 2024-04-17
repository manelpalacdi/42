# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 11:47:10 by mpalacin          #+#    #+#              #
#    Updated: 2024/04/17 12:14:49 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

SOURCES = errors.c ft_atoi.c ft_isdigit.c ft_split.c ft_strlen.c \
		  init_stack.c main.c push.c push_swap.c reverse_rotate.c \
		  rotate.c stack_utils.c stack_utils2.c swap.c tiny_sort.c \
		  push_swap_utils.c

CC = cc

OBJECTS = $(SOURCES:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
