/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:52:50 by mlamrani          #+#    #+#             */
/*   Updated: 2024/03/03 10:59:55 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE_1 "Invalid inputs !"
# define ERROR_MESSAGE_2 "Please enter : \n\t./fractol mandelbrot or \n\
        ./fractol julia <value_1><value_2> or \n\
	./fractol tricon\"\n"

# define WIDTH 800
# define HEIGHT 800

// colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY 0x808080
# define SILVER 0xC0C0C0
# define MAROON 0x800000
# define OLIVE 0x808000
# define LIME 0x00FF00
# define AQUA 0x00FFFF
# define TEAL 0x008080
# define NAVY 0x000080
# define FUCHSIA 0xFF00FF
# define PURPLE 0x800080
# define RAINBOW 0xFF00FF       // Rainbow
# define ELECTRIC 0x7FFF00      // Electric Green
# define PSYCHEDELIC 0xFF1493   // Psychedelic Pink
# define NEON_YELLOW 0xDFFF00   // Neon Yellow
# define NEON_PINK 0xFF6EC7     // Neon Pink
# define ACID_GREEN 0xB0BF1A    // Acid Green
# define RAVE_BLUE 0x007FFF     // Rave Blue
# define TRIPPY_PURPLE 0x8A2BE2 // Trippy Purple
# define BLAZING_RED 0xFF4500   // Blazing Red
# define COSMIC_BLUE 0x2E2EFE   // Cosmic Blue
# define ZENITH_YELLOW 0xFFF600 // Zenith Yellow
# define ELECTRIC_BLUE 0x7DF9FF // Electric Blue

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
	double	escaper;
	int		iter;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

/*--- strings utils ---*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		fd_putstr(char *s, int fd);
int			check_values(char *str, int dot_count, int sign_count,
				int numeric_flag);
void		exitwitherror(int x);

/*--- init ---*/
void		init_fract(t_fractal *fractal);

/*--- math utils ---*/
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	add(t_complex z1, t_complex z2);
t_complex	square(t_complex z, int i);
double		ascii_to_double(char *str);

/*--- render ---*/
void		render(t_fractal *fractal);

/*--- event ---*/
int			key_handler(int keysym, t_fractal *param);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			zoom_tracker(int button, int x, int y, t_fractal *fractal);
/*--- clean up ---*/
int			x_close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			tracker(int x, int y, t_fractal *fractal);

#endif
