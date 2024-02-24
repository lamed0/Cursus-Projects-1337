#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;
    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
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
    z.x = 0.0;
    z.y = 0.0;

    c.x = (map(x, -2, +2, 0, width) * fractal->zoom) + fractal->shift_x;
    c.y = (map(y, +2, -2, 0, height) * fractal->zoom) + fractal->shift_y;
    while (i < fractal->iter)
    {
        z = add(square(z), c);
        if ((z.x * z.x) + ( z.y * z.y) > fractal->escaper)
        {
            color = map(i, BLACK, WHITE, 0, fractal->iter);
            my_pixel_put(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, BLACK);
}

void render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < height)
    {
        x = -1;
          while (++x < width)
        {
            handler(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_ptr,
                            fractal->mlx_win,
                            fractal->img.img_ptr,
                            0,0);
}