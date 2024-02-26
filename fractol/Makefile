CFLAGS = -Wall -Wextra -Werror

CC = cc 

MLX_FLAG = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

MAIN = main.c

FUNCTIONS = events.c fractol_render.c init.c math_utils.c string_utils.c


all : $(NAME)

$(NAME) : $(MAIN) $(FUNCTIONS)
	$(CC) $(CFLAGS) $(MLX_FLAG)


.PHONY : clean fclean re 

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

re : fclean clean all