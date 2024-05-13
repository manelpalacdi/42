# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 09:18:30 by mpalacin          #+#    #+#              #
#    Updated: 2024/05/13 11:44:54 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_printf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror 

SOURCES := ft_printf.c printnumbers.c printchar.c

OBJECTS = $(SOURCES:.c=.o)

HEADER := ft_printf.h

all: $(NAME)


$(NAME): $(OBJECTS)
	ar -rc $@ $?

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
