/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:33:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/10 19:34:11 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_set_opacity(t_point *points, t_design *design)
{
	int	i;

	i = -1;
	while (++i < design->size)
	{
		if (points[i].select != design->event.sel_line.z)
		{
			points[i].color = (((points[i].color & 0xFF) >> 2)) + \
			((((points[i].color >> 8) & 0xFF) >> 2) << 8) + \
			((((points[i].color >> 16) & 0xFF) >> 2) << 16);
		}
	}
}

void	ft_sel_point(t_point *copy, t_design *design)
{
	int		i;
	float	max_dif;
	float	dif_x;
	float	dif_y;

	i = -1;
	max_dif = FLT_MAX;
	while (++i < design->size)
	{
		dif_x = design->event.sel_line.x - copy[i].x;
		dif_y = design->event.sel_line.y - copy[i].y;
		if (ft_module(dif_x, dif_y) < max_dif)
		{
			max_dif = ft_module(dif_x, dif_y);
			design->event.sel_line.z++;
			copy[i].select = design->event.sel_line.z;
		}
	}
	ft_set_opacity(copy, design);
}

void	ft_div_z(t_point *points, float div, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		points[i].z /= div;
}

void	ft_proportion_z(t_point *copy, t_design *design)
{
	static int	i = 0;
	float		mod;
	t_lli		dif_z;

	mod = ft_module(design->width, design->height);
	dif_z = design->max_z - design->min_z;
	dif_z = llabs(dif_z);
	if (!i && dif_z >> 1 <= design->width)
	{
		design->z_div = 1;
		i++;
	}
	ft_div_z(copy, design->z_div, design->size);
}

void	ft_config_points(t_point *copy, t_design *design)
{
	ft_proportion_z(copy, design);
	if (design->event.sphere)
		ft_convert_rect(design, design->copy, design->size);
	ft_rotate_z(copy, design->angle[2], design->size);
	ft_rotate_x(copy, design->angle[0], design->size);
	ft_rotate_y(copy, design->angle[1], design->size);
	ft_scale(copy, design->event.scale * design->event.zoom.z, \
		design->event.scale * design->event.zoom.z, design->size);
	ft_traslate(copy, (design->new_center[0]), \
		(design->new_center[1]), design->size);
	if (design->event.sel_line.z)
		ft_sel_point(copy, design);
}
