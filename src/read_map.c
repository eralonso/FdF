/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:21:14 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/03 09:26:03 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_read_map(int *fd, t_design *design, int width, int height)
{
	char	*line;
	char	**cord;
	int		y;

	design->width = width;
	design->height = height;
	design->points = ft_calloc(sizeof(t_point), width * height + 1);
	if (!design->points)
		return (0);
	y = 0;
	line = get_next_line(*fd);
	while (line)
	{
		cord = ft_split(line, ' ');
		ft_free(&line, 2);
		if (!cord)
			return (ft_free((char **)&design->points, 2) != NULL);
		ft_create_line_points(design, y, cord);
		ft_free(cord, 1);
		line = get_next_line(*fd);
		y++;
	}
	if (ft_close(fd) == -1)
		return (0);
	return (1);
}

void	ft_create_line_points(t_design *design, int y, char **cord)
{
	int			x;
	static int	idx = 0;

	x = -1;
	while (++x < design->width)
	{
		design->points[idx].x = x - (design->width / 2);
		design->points[idx].y = y - (design->height / 2);
		design->points[idx].z = ft_atoi(cord[x]);
		if (ft_strchr(cord[x], ','))
			design->points[idx].color = ft_atoi(ft_strchr(cord[x], ',') + 1);
		else
			design->points[idx].color = WHITE;
		idx++;
	}
}
