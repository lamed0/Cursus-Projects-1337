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
