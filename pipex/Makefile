# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 10:47:06 by mpalacin          #+#    #+#              #
#    Updated: 2024/05/07 12:39:15 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = main.c error_utils.c process.c input.c output.c path.c

OBJECTS =  $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_LIB = $(MLX_PATH)libmlx.a

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

FT_PRINTF_PATH = ft_printf/

FT_PRINTF_LIB = $(FT_PRINTF_PATH)ft_printf.a

all: subsystems $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_LIB) $(FT_PRINTF_LIB)

%.o: %.c pipex.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

subsystems:
	@echo $(B)
	make -C $(LIBFT_PATH) all
	make -C $(FT_PRINTF_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	@rm -f $(OBJECTS)
	@rm -f $(SOURCES:.c=.d) clean
	@echo "Deleted .o files."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_LIB)
	@rm -f $(FT_PRINTF_LIB)
	@echo "Deleted $(NAME) $(LIBFT_LIB)." 

re: fclean all

.PHONY: all clean fclean re subsystems
