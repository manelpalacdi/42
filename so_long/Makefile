NAME = so_long

SOURCES = main.c graphics.c map_utils.c error_utils.c input.c map.c movement.c

OBJECTS =  $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 

MLX_PATH = minilibx-linux/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

all: subsystems $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(MLX_FLAGS)	

%.o: %.c so_long.h Makefile
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "Creat $@ sense errors."

subsystems:
	@echo $(B)
	make -C $(MLX_PATH) all
	@echo $(B)
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	@rm -f $(OBJECTS)
	@echo "Deleted .o files."

fclean: clean
	@rm -f $(NAME)
	@echo "Deleted $(NAME)." 

re: fclean all

.PHONY: all clean fclean re
