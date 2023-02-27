/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:33:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/27 19:12:09 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_rotate_x(t_point *points, float angle, int size)
{
	float	y;
	float	z;
	float	rad;
	int		i;

	rad = (angle * M_PI) / 180;
	i = -1;
	while (++i < size)
	{
		y = points[i].y;
		z = points[i].z;
		points[i].y = (y * cos(rad)) + (z * (-sin(rad)));
		points[i].z = (y * sin(rad)) + (z * cos(rad));
	}
}

void	ft_rotate_y(t_point *points, float angle, int size)
{
	float	x;
	float	z;
	float	rad;
	int		i;

	rad = (angle * M_PI) / 180;
	i = -1;
	while (++i < size)
	{
		x = points[i].x;
		z = points[i].z;
		points[i].x = (x * cos(rad)) + (z * sin(rad));
		points[i].z = (x * (-sin(rad))) + (z * cos(rad));
	}
}

void	ft_rotate_z(t_point *points, float angle, int size)
{
	float	x;
	float	y;
	float	rad;
	int		i;

	rad = (angle * M_PI) / 180;
	i = -1;
	while (++i < size)
	{
		x = points[i].x;
		y = points[i].y;
		points[i].x = (x * cos(rad)) + (y * (-sin(rad)));
		points[i].y = (x * sin(rad)) + (y * cos(rad));
	}
}

void	ft_zoom_in(t_point *points, t_design *design, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (design->zoom.x < 0)
			points[i].x += -(design->zoom.x / (design->scale));
		if (design->zoom.x > 0)
			points[i].x -= (design->zoom.x / (design->scale));
		if (design->zoom.y < 0)
			points[i].y += -(design->zoom.y / (design->scale));
		if (design->zoom.y > 0)
			points[i].y -= (design->zoom.y / (design->scale));
	}
}

void	ft_zoom_out(t_point *points, t_design *design, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (design->zoom.x < 0)
			points[i].x -= -(design->zoom.x / (design->zoom.z));
		if (design->zoom.x > 0)
			points[i].x += (design->zoom.x / (design->zoom.z));
		if (design->zoom.y < 0)
			points[i].y -= -(design->zoom.y / (design->zoom.z));
		if (design->zoom.y > 0)
			points[i].y += (design->zoom.y / (design->zoom.z));
	}
}

void	ft_set_transparency(t_point *points, t_design *design)
{
	int	i;

	i = -1;
	while (++i < design->size)
	{
		if (points[i].select != design->sel_line.z)
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
		dif_x = design->sel_line.x - copy[i].x;
		dif_y = design->sel_line.y - copy[i].y;
		if (ft_module(dif_x, dif_y) < max_dif)
		{
			max_dif = ft_module(dif_x, dif_y);
			design->sel_line.z++;
			copy[i].select = design->sel_line.z;
		}
	}
	ft_set_transparency(copy, design);
}

void	ft_proportion_z(t_point *copy, t_design *design)
{
	float	mod;
	int		i;
	t_lli	dif_z;

	mod = ft_module(design->width, design->height);
	dif_z = design->max_z - design->min_z;
	dif_z = llabs(dif_z);
	if (dif_z >> 1 > design->width)
	{
		i = -1;
		while (++i < design->size)
			copy[i].z /= (dif_z >> 4);
	}
}

void	ft_scale(t_point *points, float x, float y, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		points[i].x *= x;
		points[i].y *= y;
	}
}

void	ft_traslate(t_point *points, float x, float y, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		points[i].x += x;
		points[i].y += y;
	}
}

void	ft_config_points(t_point *copy, t_design *design)
{
	ft_proportion_z(copy, design);
	ft_rotate_z(copy, design->angle[2], design->size);
	ft_rotate_x(copy, design->angle[0], design->size);
	ft_rotate_y(copy, design->angle[1], design->size);
	ft_scale(copy, design->scale * design->zoom.z, \
		design->scale * design->zoom.z, design->size);
	ft_traslate(copy, (WIN_WIDTH / 2) + design->shift.x, \
		(WIN_HEIGHT / 2) + design->shift.y, design->size);
	if (design->zoom.color == 1)
		ft_zoom_in(copy, design, design->size);
	else if (design->zoom.color == 2)
		ft_zoom_out(copy, design, design->size);
	if (design->sel_line.z)
		ft_sel_point(copy, design);
}
