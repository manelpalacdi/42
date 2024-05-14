# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 11:42:52 by mpalacin          #+#    #+#              #
#    Updated: 2024/05/14 12:41:51 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

SOURCES = main.c errors.c process.c files.c path.c

BSOURCES = bonus/main_bonus.c bonus/utils_bonus.c bonus/errors_bonus.c bonus/process_bonus.c bonus/files_bonus.c bonus/path_bonus.c

OBJECTS =  $(SOURCES:.c=.o)

BOBJECTS = $(BSOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

HEADER = pipex.h

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

GET_NEXT_LINE_PATH = get_next_line/

GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_PATH)get_next_line.a

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_PATH) all
	make -C $(GET_NEXT_LINE_PATH) all
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB)

$(NAME_BONUS): $(BOBJECTS)
	make -C $(LIBFT_PATH) all
	make -C $(GET_NEXT_LINE_PATH) all
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BOBJECTS) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(GET_NEXT_LINE_PATH) clean
	@rm -f $(OBJECTS)
	@rm -f $(BOBJECTS)
	@rm -f $(SOURCES:.c=.d) clean
	@rm -f $(BSOURCES:.c=.d) clean
	@echo "Cleaned."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(LIBFT_LIB)
	@rm -f $(GET_NEXT_LINE_LIB)
	@echo "Deleted $(NAME) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB)." 

re: fclean all

.PHONY: all clean fclean re subsystems bonus
