NAME = so_long

SOURCES = 

OBJECTS =  $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $@ $?

%.o: %.c libft.h Makefile
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "Creat $@ sense errors."

clean:
	@rm -f $(OBJECTS)
	@echo "Deleted .o files."

fclean: clean
	@rm -f $(NAME)
	@echo "Deleted $(NAME)." 

re: fclean all

.PHONY: all clean fclean re
