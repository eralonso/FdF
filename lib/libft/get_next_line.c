/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:50:46 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/07 17:56:36 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

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

void	ft_read_file(t_data *data)
{
	int	bytes;

	data->line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!data->line)
		data->err = !ft_free(&(data->buffer), 2);
	bytes = 1;
	while (!data->err && bytes && !ft_strchr(data->buffer, '\n'))
	{
		bytes = read(data->fd, data->line, BUFFER_SIZE);
		if (bytes == -1)
			data->err = !ft_free(&(data->buffer), 2);
		else
		{
			if (*data->line || data->buffer)
			{
				data->line[bytes] = '\0';
				data->buffer = ft_malloc_strjoin(data->buffer, data->line);
				if (!data->buffer)
					data->err = 1;
			}
		}
	}
	ft_free(&(data->line), 2);
}

void	ft_get_line(t_data *data)
{
	int	len;

	if (!*data->buffer)
	{
		data->line = NULL;
		return ;
	}
	len = 0;
	while (data->buffer[len] && data->buffer[len] != '\n')
		len++;
	data->line = ft_substr(data->buffer, 0, len + 1);
	if (!data->line)
		data->err = 1;
}

void	ft_clean_buffer(t_data *data)
{
	char	*aux;
	int		start;

	start = 0;
	while (data->buffer[start] && data->buffer[start] != '\n')
		start++;
	aux = ft_strdup(data->buffer);
	if (!aux)
	{
		data->err = !ft_free(&(data->buffer), 2);
		return ;
	}
	ft_free(&(data->buffer), 2);
	data->buffer = ft_substr(aux, start + 1, (ft_strlen(aux) - start));
	if (!data->buffer)
		data->err = 1;
	ft_free(&aux, 2);
}

char	*get_next_line(int fd)
{
	static t_data	data[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(data[fd]).buffer)
	{
		(data[fd]).buffer = ft_strdup("");
		if (!(data[fd]).buffer)
			return (NULL);
	}
	(data[fd]).fd = fd;
	(data[fd]).err = 0;
	if (!(data[fd]).err)
		ft_read_file(&(data[fd]));
	if (!(data[fd]).err)
		ft_get_line(&(data[fd]));
	if (!(data[fd]).err)
		ft_clean_buffer(&(data[fd]));
	if ((data[fd]).err || !ft_strchr((data[fd]).line, '\n'))
		ft_free(&((data[fd]).buffer), 2);
	return ((data[fd]).line);
}
