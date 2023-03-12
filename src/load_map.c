/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:21:14 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/12 19:10:22 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_load_map(t_design *design)
{
	float	mod;

	if (!ft_load_points(design))
		return (0);
	ft_color(design);
	mod = ft_module(design->width, design->height);
	design->event.scale = (WIN_HEIGHT) / mod;
	ft_polarize(design, design->points, design->size);
	design->inc_x = 1;
	design->inc_y = design->width;
	ft_printf(1, "\n");
	printf("scale == %f\n", design->event.scale);
	return (1);
}

int	ft_load_points(t_design *design)
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
		design->points[idx].select = 0;
		if (ft_strchr(cord[x], ','))
		{
			design->points[idx].color = ft_atoi(ft_strchr(cord[x], ',') + 1);
			design->points[idx].hexa = 1;
		}
		idx++;
	}
}

void	ft_color(t_design *design)
{
	int	i;

	i = -1;
	while (++i < design->size)
		ft_set_color(design, &design->points[i], design->min_z, design->max_z);
}
