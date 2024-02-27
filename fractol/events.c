/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:52:12 by mlamrani          #+#    #+#             */
/*   Updated: 2024/02/27 14:47:40 by mlamrani         ###   ########.fr       */
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
    printf("%d\n", keysym);
    if (keysym == XK_Escape)
        x_close_handler(fractal);
    if (keysym == XK_Left)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_y -= (0.5* fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_y += (0.5* fractal->zoom);
    else if (keysym == 61 || keysym == 65451)
        fractal->iter += 10;
    else if (keysym == XK_minus || keysym == 65453)
        fractal->iter -= 10;
    
    render(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    (void)x;
    (void)y;
    if (button == Button4)
    {
        fractal->zoom *= 0.95;
    }
    else if (button == Button5)
    {
        fractal->zoom *= 1.05;
    }
    render(fractal);
    return (0);
}

int tracker(int x, int y, t_fractal *fractal)
{  
    if (!ft_strncmp(fractal->name, "julia", 5))
    {
        fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
        fractal->julia_y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
        render(fractal);
    }
    return (0);
}

int zoom_tracker(int button, int x, int y, t_fractal *fractal) 
{
    double zoom_factor;
    double new_zoom;
    double mouse_x;
    double mouse_y;
    
    
    if (button == 4 || button == 5) 
    { // Check if the mouse wheel is scrolled up or down
        if (button == 4)
            zoom_factor = 0.9;
        else
            zoom_factor = 1.1;
        // Adjust zoom level based on mouse position
        new_zoom = fractal->zoom * zoom_factor;
        mouse_x = map(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
        mouse_y = map(y, 2, -2, HEIGHT) * fractal->zoom + fractal->shift_y;
        fractal->shift_x = mouse_x - (mouse_x - fractal->shift_x) * zoom_factor;
        fractal->shift_y = mouse_y - (mouse_y - fractal->shift_y) * zoom_factor;

        // Re-render fractal with updated zoom level
        render(fractal);
    }
    return (0);
}