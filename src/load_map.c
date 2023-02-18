/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:21:14 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:24 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_load_map(t_design *design)
{
	char	**map;
	char	**line;
	int		y;

	design->points = ft_calloc(sizeof(t_point), design->size + 1);
	if (!design->points)
		return (0);
	y = -1;
	map = ft_split(design->map, '\n');
	if (!map)
		return (ft_free((char **)&design->points, 2) == NULL);
	while (++y < design->height)
	{
		line = ft_split(map[y], ' ');
		if (!line)
			return (ft_free((char **)&design->points, 2) == NULL && \
				ft_free(map, 1) != NULL);
		ft_fill_line_points(design, y, line);
		ft_free(line, 1);
		ft_printf(1, "   \rLoading map: %i,%i%%   \r", (design->width * y * \
	100) / design->size, (int)(((((float)(design->width * y * 100) / design->\
	size) * 100) - (((design->width * y * 100) / design->size) * 100))));
	}
	return (ft_free(map, 1) == NULL);
}

void	ft_fill_line_points(t_design *design, int y, char **cord)
{
	int			x;
	static int	idx = 0;

	x = -1;
	while (++x < design->width)
	{
		design->points[idx].x = x - ((float)design->width / 2);
		design->points[idx].y = y - ((float)design->height / 2);
		design->points[idx].z = ft_atoi(cord[x]);
		if (!idx || design->points[idx].z > design->max_z)
			design->max_z = ft_atoi(cord[x]);
		if (!idx || design->points[idx].z < design->min_z)
			design->min_z = ft_atoi(cord[x]);
		design->points[idx].hexa = 0;
		if (ft_strchr(cord[x], ','))
		{
			design->points[idx].color = ft_atoi(ft_strchr(cord[x], ',') + 1);
			design->points[idx].hexa = 1;
		}
		else
			design->points[idx].color = WHITE;
		idx++;
	}
}
