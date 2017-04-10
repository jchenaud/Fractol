/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:11:06 by jchenaud          #+#    #+#             */
/*   Updated: 2017/01/27 09:04:26 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_strrjoin(char const *s1, char const *s2)
{
	unsigned int	u_i;
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_i = 0;
	u_j = 0;
	u_size = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(*dest) * (u_size + 1))))
		return (NULL);
	while (s1[u_i] != '\0')
	{
		dest[u_i] = s1[u_i];
		u_i++;
	}
	free((char *)s1);
	while (s2[u_j] != '\0')
	{
		dest[u_i + u_j] = s2[u_j];
		u_j++;
	}
	dest[u_i + u_j] = '\0';
	return (dest);
}

static char	**ft_line(char *str, char **line)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != 10)
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != 0 && str[i] != 10)
	{
		line[0][i] = str[i];
		i++;
	}
	line[0][i] = 0;
	return (line);
}

static char	*ft_gnl_ext_one(t_struct s, char *str, const int fd)
{
	str = (char *)malloc(sizeof(char *) * BUFF_SIZE + 1);
	if (str == NULL)
		return (NULL);
	s.buf[s.red] = 0;
	str = ft_strrjoin(str, s.buf);
	while (s.red == BUFF_SIZE)
	{
		s.red = read(fd, s.buf, BUFF_SIZE);
		s.nb++;
		if (s.red == BUFF_SIZE)
		{
			str = ft_realloc(str, ((s.nb * BUFF_SIZE) + 1));
			if (!(str = ft_strrjoin(str, s.buf)))
				return (NULL);
		}
	}
	s.buf[s.red] = 0;
	if (s.nb > 1)
	{
		str = ft_realloc(str, ((s.nb * BUFF_SIZE) + 1 + s.red));
		if (!(str = ft_strrjoin(str, s.buf)))
			return (NULL);
	}
	free(s.buf);
	return (str);
}

static char	*ft_gnl_ext_two(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0 && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	if (str[i] == 0)
		str = NULL;
	if (str == NULL)
		return (NULL);
	else
		ft_strcpy(str, &str[i]);
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	t_struct	s;

	if (line == NULL)
		return (-1);
	if (str == NULL)
	{
		s.nb = 1;
		if (!(s.buf = (char *)malloc(sizeof(char *) * BUFF_SIZE + 1)))
			return (-1);
		s.red = read(fd, s.buf, BUFF_SIZE);
		if (s.red == 0)
			return (0);
		if (s.red < 0 || s.buf == NULL || !(str = ft_gnl_ext_one(s, str, fd)))
			return (-1);
	}
	else
	{
		str = ft_gnl_ext_two(str);
		if (str == NULL)
			return (0);
	}
	if (!(line = ft_line(str, line)))
		return (-1);
	return (1);
}
