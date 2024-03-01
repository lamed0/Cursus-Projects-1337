/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:53:06 by mlamrani          #+#    #+#             */
/*   Updated: 2024/03/01 09:47:23 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_malloc(void)
{
	perror("Problems with malloc!");
	exit(1);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escaper = 4;
	fractal->iter = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask,
		x_close_handler, fractal);
	mlx_hook(fractal->mlx_win, MotionNotify, PointerMotionMask, tracker,
		fractal);
	mlx_hook(fractal->mlx_win, ButtonRelease, ButtonReleaseMask, zoom_tracker,
		fractal);
}

void	init_fract(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (NULL == fractal->mlx_ptr)
		error_malloc();
	fractal->mlx_win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			fractal->name);
	if (NULL == fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		error_malloc();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		error_malloc();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	event_init(fractal);
	data_init(fractal);
}
