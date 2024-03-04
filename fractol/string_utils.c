/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:53:37 by mlamrani          #+#    #+#             */
/*   Updated: 2024/03/03 11:00:12 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
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

void	check_initial_character(char *str, int *dot_count, int *sign_count,
		int *numeric_flag)
{
	if (*str == '-' || *str == '+')
		(*sign_count)++;
	else if (*str == '.')
		(*dot_count)++;
	else if (*str >= '0' && *str <= '9')
		(*numeric_flag) = 1;
	else
		exitwitherror(1);
}

void	dot_checker(char *str, int *dot_count, int *numeric_flag)
{
	if (*(str + 1) == '\0' || !(*numeric_flag))
		exitwitherror(1);
	(*dot_count)++;
	if (*dot_count > 1)
		exitwitherror(1);
}

int	check_values(char *str, int dot_count, int sign_count, int numeric_flag)
{
	while (*str && *str == ' ')
		str++;
	if ((*str == '-' || *str == '+') && *(str + 1) == '.')
		str++;
	while (*str)
	{
		check_initial_character(str, &dot_count, &sign_count, &numeric_flag);
		while (*++str)
		{
			if (*str == '.')
			{
				dot_checker(str, &dot_count, &numeric_flag);
			}
			else if (*str >= '0' && *str <= '9')
				numeric_flag = 1;
			else
				exitwitherror(1);
		}
	}
	if (!numeric_flag)
		exitwitherror(1);
	return (0);
}
