# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 10:47:06 by mpalacin          #+#    #+#              #
#    Updated: 2024/04/30 10:59:18 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = main.c error_utils.c input.c

OBJECTS =  $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_LIB = $(MLX_PATH)libmlx.a

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

all: subsystems $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_LIB)

%.o: %.c pipex.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

subsystems:
	@echo $(B)
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@rm -f $(SOURCES:.c=.d) clean
	@echo "Deleted .o files."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_LIB)
	@echo "Deleted $(NAME) $(LIBFT_LIB)." 

re: fclean all

.PHONY: all clean fclean re subsystems
