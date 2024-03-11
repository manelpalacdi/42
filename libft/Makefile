# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 11:57:33 by mpalacin          #+#    #+#              #
#    Updated: 2024/02/02 09:33:40 by mpalacin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		  ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		   ft_lstmap.c

OBJECTS =  $(SOURCES:.c=.o)

BOBJECTS = $(BSOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $@ $?

bonus: $(NAME) $(BOBJECTS)
	@ar -rc $(NAME) $(BOBJECTS)
	@touch bonus

%.o: %.c libft.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Creat $@ sense errors."

clean:
	@rm -f $(OBJECTS)
	@rm -f $(BOBJECTS)
	@rm -f bonus
	@echo "Deleted .o files."

fclean: clean
	@rm -f $(NAME)
	@echo "Deleted $(NAME)." 

re: fclean all

.PHONY: all clean fclean re
