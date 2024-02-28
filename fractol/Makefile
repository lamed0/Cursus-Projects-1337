CFLAGS = -Wall -Wextra -Werror
CC = cc
MLX_FLAG = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
NAME = fractol
MAIN = main.c
FUNCTIONS = events.c fractol_render.c init.c math_utils.c string_utils.c burning.c

all: $(NAME)

$(NAME): $(MAIN) $(FUNCTIONS)
	$(CC) $(CFLAGS) $(MAIN) $(FUNCTIONS) $(MLX_FLAG) -o $(NAME)

.PHONY: clean fclean re

clean:
	@echo "Nothing to clean"

fclean: clean
	rm -f $(NAME)

re: fclean all