/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:52:32 by mlamrani          #+#    #+#             */
/*   Updated: 2024/02/27 15:10:05 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;
    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}
static void man_or_jul(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (!ft_strncmp(fractal->name, "julia", 5))
    {
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
    else
    {
        c->x = z->x;
        c->y = z->y;
    }
}

            //z = z^2 + c
            //z initially is (0,0)
            //c is the actual point

static void handler(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;
    i = 0;
    // z.x = 0.0;
    // z.y = 0.0;

    z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
    man_or_jul(&z, &c, fractal);
    while (i < fractal->iter)
    {
        z = add(square(z), c);
        if ((z.x * z.x) + ( z.y * z.y) > fractal->escaper)
        {
            color = map(i, BLUE, RED, fractal->iter);
            my_pixel_put(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, ACID_GREEN);
}

void render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (++y < HEIGHT)
    {
        x = 0;
          while (++x < WIDTH)
        {
            handler(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_ptr,
                            fractal->mlx_win,
                            fractal->img.img_ptr,
                            0,0);
}