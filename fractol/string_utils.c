/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:53:37 by mlamrani          #+#    #+#             */
/*   Updated: 2024/02/26 12:20:42 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	if (n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

void	fd_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if (fd > 0)
	{
		while (s[i])
			write(fd, &s[i++], 1);
	}
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
