/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:21:14 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/07 18:56:36 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_load_map(t_design *design, int width, int height)
{
	char	**map;
	char	**line;
	int		y;

	design->width = width;
	design->height = height;
	design->points = ft_calloc(sizeof(t_point), width * height + 1);
	if (!design->points)
		return (0);
	y = 0;
	map = ft_split(design->map, '\n');
	if (!map)
			return (ft_free((char **)&design->points, 2) == NULL);
	while (y < height)
	{
		line = ft_split(map[y], ' ');
		if (!line)
			return (ft_free((char **)&design->points, 2) == NULL && \
					ft_free(map, 1) != NULL);
		ft_fill_line_points(design, y, line);
		ft_free(line, 1);
		y++;
		ft_printf(1, "\r  Loading map: %i,%i%%  \r", (width * y * 100)\
		 / (width * height), (width * y) % (width * height));
	}
	ft_free(map, 1);
	//ft_printf(1, "\n");
	return (1);
}

void	ft_fill_line_points(t_design *design, int y, char **cord)
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
