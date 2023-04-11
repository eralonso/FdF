/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:33:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/11 18:17:40 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_check_sel_point(t_design *design, t_point point, int idx)
{
	if (point.select != design->event.sel_line.z && \
		!(design->points[idx].x == design->event.sel_point.x && \
		design->points[idx].y == design->event.sel_point.y && \
		design->points[idx].z == design->event.sel_point.z && \
		design->event.k_cmd))
		return (1);
	else
		return (0);
}

void	ft_set_opacity(t_point *points, t_design *design, int size[2], \
		int iterator)
{
	int	iter[2];
	int	idx;

	iter[0] = 0;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			if (ft_check_sel_point(design, points[idx], idx))
			{
				points[idx].color = (((points[idx].color & 0xFF) >> 2)) + \
				((((points[idx].color >> 8) & 0xFF) >> 2) << 8) + \
				((((points[idx].color >> 16) & 0xFF) >> 2) << 16);
			}
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}

void	ft_sel_point(t_point *copy, t_design *design, int size[2], int iterator)
{
	int		iter[3];
	float	dif[3];

	iter[0] = 0;
	dif[2] = FLT_MAX;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			iter[2] = iter[1] + (size[0] * iter[0]);
			dif[0] = design->event.sel_line.x - copy[iter[2]].x;
			dif[1] = design->event.sel_line.y - copy[iter[2]].y;
			if (!(design->event.sphere && copy[iter[2]].z < 0) && \
				ft_module(dif[0], dif[1]) < dif[2])
			{
				dif[2] = ft_module(dif[0], dif[1]);
				copy[iter[2]].select = ++(design->event.sel_line.z);
				if (design->event.put_pt == 1)
					design->event.sel_point = design->points[iter[2]];
			}
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}

void	ft_div_z(t_point *points, float div, int size[2], int iterator)
{
	int		iter[2];
	int		idx;

	iter[0] = 0;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			points[iter[1] + (size[0] * iter[0])].z = \
			(int)(points[idx].z / div);
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}

// void	ft_proportion_z(t_point *copy, t_design *design)
// {
// 	ft_div_z(copy, design->prop.z_div, design->info.size, design->info.inc_x);
// }
	// float		mod;
	// t_lli		dif_z;

	// mod = ft_module(design->width, design->height);
	// dif_z = design->max_z - design->min_z;
	// dif_z = llabs(dif_z);
	// if (dif_z <= mod / 2)
	// 	design->z_div = 1;

void	ft_config_points(t_point *copy, t_stat info, t_design *design)
{
	float	config[2];
	int		size[2];

	size[0] = info.width;
	size[1] = info.height;
	ft_div_z(copy, design->prop.z_div, size, info.inc_x);
	if (design->event.sphere)
		ft_convert_rect(design, copy, size, info.inc_x);
	ft_rotate_z(copy, design->prop.angle[2], size, info.inc_x);
	ft_rotate_x(copy, design->prop.angle[0], size, info.inc_x);
	ft_rotate_y(copy, design->prop.angle[1], size, info.inc_x);
	config[0] = design->event.scale * design->event.zoom.z;
	config[1] = design->event.scale * design->event.zoom.z;
	ft_scale(copy, config, size, info.inc_x);
	ft_traslate(copy, design->prop.new_center, size, info.inc_x);
	if (design->event.sel_line.z)
	{
		ft_sel_point(copy, design, size, info.inc_x);
		ft_set_opacity(copy, design, size, info.inc_x);
		design->event.put_pt = 2;
	}
}
// ft_proportion_z(copy, design);
