# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 10:47:06 by mpalacin          #+#    #+#              #
#    Updated: 2024/05/13 13:13:34 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = main.c errors.c process.c files.c path.c

BSOURCES = utils_bonus.c 

OBJECTS =  $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

HEADER = pipex.h

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

GET_NEXT_LINE_PATH = get_next_line/

GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_PATH)get_next_line.a

all: subsystems $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(GET_NEXT_LINE_LIB)

%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

subsystems:
	@echo $(B)
	make -C $(LIBFT_PATH) all
	make -C $(GET_NEXT_LINE_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(GET_NEXT_LINE_PATH) clean
	@rm -f $(OBJECTS)
	@rm -f $(SOURCES:.c=.d) clean
	@echo "Deleted .o files."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_LIB)
	@rm -f $(GET_NEXT_LINE_LIB)
	@echo "Deleted $(NAME) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB)." 

re: fclean all

.PHONY: all clean fclean re subsystems
