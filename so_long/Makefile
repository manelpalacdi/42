# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 11:34:36 by mpalacin          #+#    #+#              #
#    Updated: 2024/04/04 12:42:16 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = main.c graphics.c map_utils.c error_utils.c input.c map.c check_matrix.c movement.c get_next_line.c get_next_line_utils.c

OBJECTS =  $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

all: subsystems $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(MLX_FLAGS) $(LIBFT_LIB) $(MLX_LIB)

%.o: %.c so_long.h get_next_line.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

subsystems:
	@echo $(B)
	make -C $(MLX_PATH) all
	@echo $(B)
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	@rm -f $(OBJECTS)
	@rm -f $(SOURCES:.c=.d) clean
	@echo "Deleted .o files."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_LIB)
	@rm -f $(MLX_LIB)
	@echo "Deleted $(NAME) $(LIBFT_LIB) $(MLX_LIB)." 

re: fclean all

.PHONY: all clean fclean re
