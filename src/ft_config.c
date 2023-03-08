/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:33:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/08 19:30:42 by eralonso         ###   ########.fr       */
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
	t_point	dif;
	float	mod;

	i = -1;
	max_dif = FLT_MAX;
	while (++i < design->size)
	{
		dif.x = design->event.sel_line.x - copy[i].x;
		dif.y = design->event.sel_line.y - copy[i].y;
		mod = ft_module(dif.x, dif.y);
		if (mod < max_dif)
		{
			max_dif = mod;
			design->event.sel_line.z++;
			copy[i].select = design->event.sel_line.z;
		}
	}
	ft_set_opacity(copy, design);
}

static long long int	ft_llabs(long long int num)
{
	if (num < 0)
		return (-num);
	return (num);
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
	float	mod;
	t_lli	dif_z;
	t_lli	dif;

	mod = ft_module(design->width, design->height);
	dif_z = design->max_z - design->min_z;
	dif_z = ft_llabs(dif_z);
	if ((dif_z * design->event.scale) > WIN_HEIGHT / 2)
	{
		dif = ft_round(((float)dif_z * design->event.scale) / \
			((float)WIN_HEIGHT / 2));
		ft_div_z(copy, design->z_div * dif, design->size);
	}
}
	//if (dif_z >> 1 > design->width >> 1)
		//dif = (dif_z >> design->z_div);
			//copy[i].z /= dif;

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
