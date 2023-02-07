/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:50:46 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/07 16:33:09 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>
#define BUFFER_SIZE (int)500000

char	*ft_malloc_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (ft_free(&s1, 2));
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	ft_free(&s1, 2);
	return (str);
}

void	ft_read_file(t_gnl *gnl)
{
	int	bytes;

	gnl->line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!gnl->line)
		gnl->err = !ft_free(&(gnl->buffer), 2);
	bytes = 1;
	while (!gnl->err && bytes && !ft_strchr(gnl->buffer, '\n'))
	{
		bytes = read(gnl->fd, gnl->line, BUFFER_SIZE);
		if (bytes == -1)
			gnl->err = !ft_free(&(gnl->buffer), 2);
		else
		{
			if (*gnl->line || gnl->buffer)
			{
				gnl->line[bytes] = '\0';
				gnl->buffer = ft_malloc_strjoin(gnl->buffer, gnl->line);
				if (!gnl->buffer)
					gnl->err = 1;
			}
		}
	}
	ft_free(&(gnl->line), 2);
}

void	ft_get_line(t_gnl *gnl)
{
	int	len;

	if (!*gnl->buffer)
	{
		gnl->line = NULL;
		return ;
	}
	len = 0;
	while (gnl->buffer[len] && gnl->buffer[len] != '\n')
		len++;
	gnl->line = ft_substr(gnl->buffer, 0, len + 1);
	if (!gnl->line)
		gnl->err = 1;
}

void	ft_clean_buffer(t_gnl *gnl)
{
	char	*aux;
	int		start;

	start = 0;
	while (gnl->buffer[start] && gnl->buffer[start] != '\n')
		start++;
	aux = ft_strdup(gnl->buffer);
	if (!aux)
	{
		gnl->err = !ft_free(&(gnl->buffer), 2);
		return ;
	}
	ft_free(&(gnl->buffer), 2);
	gnl->buffer = ft_substr(aux, start + 1, (ft_strlen(aux) - start));
	if (!gnl->buffer)
		gnl->err = 1;
	ft_free(&aux, 2);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(gnl[fd]).buffer)
	{
		(gnl[fd]).buffer = ft_strdup("");
		if (!(gnl[fd]).buffer)
			return (NULL);
	}
	(gnl[fd]).fd = fd;
	(gnl[fd]).err = 0;
	if (!(gnl[fd]).err)
		ft_read_file(&(gnl[fd]));
	if (!(gnl[fd]).err)
		ft_get_line(&(gnl[fd]));
	if (!(gnl[fd]).err)
		ft_clean_buffer(&(gnl[fd]));
	if ((gnl[fd]).err || !ft_strchr((gnl[fd]).line, '\n'))
		ft_free(&((gnl[fd]).buffer), 2);
	return ((gnl[fd]).line);
}
