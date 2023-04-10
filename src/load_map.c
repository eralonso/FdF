/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:21:14 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/10 19:42:37 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_load_map(t_design *design)
{
	float	mod;
	t_lli	dif_z;

	if (!ft_load_points(design))
		return (0);
	ft_printf(1, "\n");
	ft_color(design);
	ft_polarize(design, design->points, design->info.size);
	mod = ft_module(design->info.width, design->info.height);
	design->event.scale = (WIN_HEIGHT + design->info.height) / mod;
	ft_calculate_incs(design);
	dif_z = design->info.max_z - design->info.min_z;
	dif_z = llabs(dif_z);
	design->prop.z_div = 1;
	if (dif_z / 32 >= 1)
		design->prop.z_div = (design->event.scale * ((float)dif_z / 64));
	printf("scale == %f\n", design->event.scale);
	printf("inc x: %ipx && inc y: %ipx\n", design->info.inc_x, \
	design->info.inc_y);
	printf("width: %ipx && height: %ipx && size: %ipx\n", design->info.width, \
	design->info.height, design->info.size);
	return (1);
}
	// design->info.inc_x = 1;
	// design->info.inc_y = design->info.width;
	// printf("mod == %f\n", mod);
	// printf("dif_z == %lli\n", dif_z);
	// printf("z max == %i\n", design->max_z);
	// printf("z min == %i\n", design->min_z);
	// printf("z_div == %f\n", design->z_div);

int	ft_load_points(t_design *design)
{
	char	**map;
	char	**line;
	int		y;

	design->points = ft_calloc(sizeof(t_point), design->info.size + 1);
	if (!design->points)
		return (0);
	y = -1;
	map = ft_split(design->map, '\n');
	if (!map)
		return (ft_free((char **)&design->points, 2) == NULL);
	while (++y < design->info.height)
	{
		line = ft_split(map[y], ' ');
		if (!line)
			return (ft_free((char **)&design->points, 2) == NULL && \
				ft_free(map, 1) != NULL);
		ft_fill_line_points(design, y, line);
		ft_free(line, 1);
		ft_printf(1, "   \rLoading map: %i,%i%%   \r", (design->info.width * y * \
	100) / design->info.size, (int)(((((float)(design->info.width * y * 100) / \
	design->info.size) * 100) - (((design->info.width * y * 100) / \
	design->info.size) * 100))));
	}
	return (ft_free(map, 1) == NULL);
}

void	ft_fill_line_points(t_design *design, int y, char **cord)
{
	int			x;
	static int	idx = 0;

	x = -1;
	while (++x < design->info.width)
	{
		design->points[idx].x = x - ((float)design->info.width / 2);
		design->points[idx].y = y - ((float)design->info.height / 2);
		design->points[idx].z = ft_atoi(cord[x]);
		if (!idx || design->points[idx].z > design->info.max_z)
			design->info.max_z = ft_atoi(cord[x]);
		if (!idx || design->points[idx].z < design->info.min_z)
			design->info.min_z = ft_atoi(cord[x]);
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
	while (++i < design->info.size)
		ft_set_color(design, &design->points[i], \
		design->info.min_z, design->info.max_z);
}
