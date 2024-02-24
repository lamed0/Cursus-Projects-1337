/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:52:12 by mlamrani          #+#    #+#             */
/*   Updated: 2024/02/24 13:52:23 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int x_close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_ptr, 
                    fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_ptr, 
                        fractal->mlx_win);
    mlx_destroy_display(fractal->mlx_ptr);
    free(fractal->mlx_ptr);
    exit(EXIT_SUCCESS);
}

int key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        x_close_handler(fractal);
    if (keysym == XK_Left)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_y += (0.5* fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_y -= (0.5* fractal->zoom);
    else if (keysym == XK_plus)
        fractal->iter += 10;
    else if (keysym == XK_minus)
        fractal->iter -= 10;
    
    render(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == Button5)
    {
        fractal->zoom *= 0.95;
    }
    else if (button == Button4)
    {
        fractal->zoom *= 1.05;
    }
    render(fractal);
    return (0);
}