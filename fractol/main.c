/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:53:19 by mlamrani          #+#    #+#             */
/*   Updated: 2024/02/28 10:16:40 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || (4 == ac
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			fractal.julia_x = ascii_to_double(av[2]);
			fractal.julia_y = ascii_to_double(av[3]);
		}
		init_fract(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		fd_putstr(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
