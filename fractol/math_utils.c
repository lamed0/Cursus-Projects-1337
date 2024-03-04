/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:53:30 by mlamrani          #+#    #+#             */
/*   Updated: 2024/03/03 12:22:58 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

t_complex	add(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square(t_complex z, int i)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = i * z.x * z.y;
	return (res);
}

double	ascii_to_double(char *str)
{
	double	int_part;
	int		sign;
	double	fract_part;
	double	decimal_multiplier;

	int_part = 0;
	sign = +1;
	fract_part = 0;
	decimal_multiplier = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str)
		int_part = (int_part * 10) + (*str++ - 48);
	if (*str == '.')
		++str;
	while (*str)
	{
		decimal_multiplier /= 10;
		fract_part = fract_part + (*str++ - 48) * decimal_multiplier;
	}
	return ((int_part + fract_part) * sign);
}

void	exitwitherror(int x)
{
	if (x == 0)
	{
		fd_putstr(ERROR_MESSAGE_2, STDERR_FILENO);
		exit(1);
	}
	else
	{
		fd_putstr(ERROR_MESSAGE_1, STDERR_FILENO);
		exit(1);
	}
}
