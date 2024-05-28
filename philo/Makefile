# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 10:11:18 by mpalacin          #+#    #+#              #
#    Updated: 2024/05/28 11:48:49 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = actions.c init.c main.c thread.c utils.c utils2.c

HEADER = philo.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

OBJECTS = $(SOURCES:.c=.o)

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
