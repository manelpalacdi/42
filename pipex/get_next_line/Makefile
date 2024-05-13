# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 09:18:30 by mpalacin          #+#    #+#              #
#    Updated: 2024/05/13 11:46:14 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := get_next_line.a

CC := cc

CFLAGS := -Wall -Wextra -Werror 

SOURCES := get_next_line.c get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

HEADER := get_next_line.h

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
