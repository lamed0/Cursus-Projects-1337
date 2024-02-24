#include "fractol.h"



int main(int ac, char **av)
{
	t_fractal	fractal;
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)
		|| 4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		//1)
		init_fract(&fractal);
		//2)
		render(&fractal);
		//3)
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		fd_putstr(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}


}

