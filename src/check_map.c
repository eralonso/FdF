/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:46:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 14:53:21 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_check_map(char *file, t_map *map)
{
	int	fd;

	if (ft_strrncmp(file, ".fdf\0", 4))
		return (ft_error(ERR_MAP, NULL, 0));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(ft_error(NULL, file, 1));
	if (!ft_check_read(fd))
		return (0);
	if (!ft_read_map(fd, map))
		return (0);
	return (1);
}

int	ft_check_read(int fd)
{
	char	*str;
	char	**line;
	int		x;

	x = 0;
	str = get_next_line(fd);
	while (str)
	{
		line = ft_split(str, ' ');
		if (!line)
			return (ft_error(ft_free(&str, 2), NULL, 0));
		if (!ft_check_valid_param(line))
			return (0);
		if (x == 0)
			x = ft_matrixlen(line);
		else if (x != ft_matrixlen(line))
			return (0);
		ft_free(line, 1);
		str = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (ft_error(NULL, 1));
	return (1);
}

int	ft_check_valid_param(char **line)
{
	int		i;
	char	**colon;

	i = -1;
	while (line[++i])
	{
		colon = NULL;
		if (ft_strchr(line[i], ','))
		{
			colon = ft_split(line[i], ',');
			if (!colon)
				return (0);
			if (ft_matrixlen(colon) > 2 || !ft_isnum(colon[0])
					|| !ft_check_hexa(colon[1]))
				return (0)
			ft_free(colon, 1);
		}
		else if (!ft_isnum(line[i]))
				return (0);
	}
	return (1);
}

int	ft_check_hexa(char *str)
{
	int	i;

	i = 1;
	if (str[0] != 0 || !ft_strchr("xX\0", str[1]))
		return (0);
	while (str[++i])
		if (!ft_strchr(BASE_HXU, str[i]) && !ft_strchr(BASE_HXL, str[i]))
			return (0);
	return (1);
}

int	ft_read_map(int fd, t_map *map)
{
	return (1);
}
