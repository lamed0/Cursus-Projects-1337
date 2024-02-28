#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;
    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

void        burning_set(int x, int y, t_fractal *burning)
{
        int                i;
        double        z0;
        double        z1;
        double        tempz0;
        t_complex c;
        int color = 0;

        i = 0;
        c.x = (x + burning->shift_x) / burning->zoom
                * (1.0 + 2.5) / (WIDTH - 1) - 2.5;
        c.y = (y + burning->shift_y) / burning->zoom
                * (1.0 + 1.0) / (WIDTH - 1) - 1.0;
        z0 = c.x;
        z1 = c.y;
        while (i++ < burning->iter)
        {
                tempz0 = z0 * z0 - z1 * z1 + c.x;
                z1 = fabs(3.0 * z0 * z1) + c.y;
                z0 = tempz0;
                if (z0 * z0 + z1 * z1 > 4)
                {
                        my_pixel_put(x, y, &burning->img, (color * i));
                        break ;
                }
        }
}
void burning(t_fractal *burning)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
          while (++x < WIDTH)
        {
            burning_set(x, y, burning);
        }
    }
}