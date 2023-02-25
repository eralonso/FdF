/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:33:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/25 12:04:28 by eralonso         ###   ########.fr       */
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

float	ft_module(float x, float y)
{
	float	mod;

	mod = sqrt(pow(x, 2) + pow(y, 2));
	return (mod);
}

void	ft_zoom_in(t_point *points, float x, float y, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (x < 0)
			points[i].x += -x;// * 1.2);//design->zoom.z);
		if (x > 0)
			points[i].x -= x;// * 1.2);//design->zoom.z);
		if (y < 0)
			points[i].y += y;// * 1.2);//design->zoom.z);
		if (y > 0)
			points[i].y += y;// * 1.2);//design->zoom.z);
	}
}

void	ft_zoom_out(t_point *points, float x, float y, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (x < 0)
			points[i].x += x;// * 1.2);//design->zoom.z);
		if (x > 0)
			points[i].x += x;// * 1.2);//design->zoom.z);
		if (y < 0)
			points[i].y -= y;// * 1.2);//design->zoom.z);
		if (y > 0)
			points[i].y += -y;// * 1.2);//design->zoom.z);
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

void	ft_translate(t_point *points, float x, float y, int size)
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
	ft_translate(copy, (WIN_WIDTH / 2) + design->shift.x, \
		(WIN_HEIGHT / 2) + design->shift.y, design->size);
	ft_zoom_in(copy, design->zoom.x, design->zoom.y, design->size);
	ft_zoom_out(copy, design->zoom.x, design->zoom.y, design->size);
	if (design->sel_line.z)
		ft_sel_point(copy, design);
	//static int i = -1;
	//if (i < 0 && design->sel_line.z)
	//	while (++i < design->size)
	//		printf("points[%i].select == %f\n", i, copy[i].select);
}
/*
void	ft_config_point(t_point *p, t_design *design, float width, float height)
{
	float	mod;
	float	real_z;
	t_lli	dif_z;
	int		restart;

	restart = 0;
	if (design->sel_line.z && (height / 2 - ((int)height % 2) - 1 == p->y \
	&& width / 2 - ((int)width % 2) - 1 == p->x))
	{
		printf("restart == 1\n");
		restart = 1;
	}
	real_z = p->z;
	mod = ft_module(width, height);
	dif_z = (design->max_z - design->min_z);
	dif_z = llabs(dif_z);
	if (dif_z >> 1 > width)
		p->z /= (dif_z >> 4);//((dif_z / width) * width);
	static int		i = 0;
	if (!i)
	{
		printf("\nINIT:\ndif_z == %lld\n", dif_z);
		printf("width == %f\n", width);
		printf("width / 2 - width %% 2 == %f\n", width / 2 - ((int)width % 2));
		printf("points[0]: p->x == %f\n", p->x);
		printf("height == %f\n", height);
		printf("size == %i\n", design->size);
		printf("mod == %f\n", mod);
		printf("max_z == %d\n", design->max_z);
		printf("min_z == %d\n\n", design->min_z);
	}
	i++;
	if (i == (width))
	{
		printf("FINISH:\ndif_z == %lld\n", dif_z);
		printf("width == %f\n", width);
		printf("width / 2 == %f\n", width / 2);
		printf("points[%i]: p->x == %f\n", i, p->x);
		printf("height == %f\n", height);
		printf("size == %i\n", design->size);
		printf("mod == %f\n", mod);
		printf("max_z == %d\n", design->max_z);
		printf("min_z == %d\n\n", design->min_z);
	}
	ft_rotate_z(p, design->angle[2]);
	ft_rotate_x(p, design->angle[0]);
	ft_rotate_y(p, design->angle[1]);
	p->z = real_z;
	p->x = (p->x * ((WIN_HEIGHT - height) / mod)) * design->zoom.z;
	p->y = (p->y * ((WIN_HEIGHT - height) / mod)) * design->zoom.z;
	p->x = (p->x + (WIN_WIDTH / 2)) + design->shift.x;
	p->y = (p->y + (WIN_HEIGHT / 2)) + design->shift.y;
	ft_zoom_in(p, design);
	ft_zoom_out(p, design);
	if (design->sel_line.z)// && !sel)
		ft_point_selected(design, p, restart);
}*/

	//if (dif_z / width >= 0.5 && p->z != 0)// && p->z / dif_z > 0.1)
	//if (dif_z >> 1 > width || dif_z > height)

	//static int		i = 0;
	/*if (!i)
	{
		printf("dif_z == %lld\n", dif_z);
		printf("width == %f\n", width);
		printf("width / 2 - width %% 2 == %f\n", width / 2 - ((int)width % 2));
		printf("points[0]: p->x == %f\n", p->x);
		printf("height == %f\n", height);
		printf("size == %i\n", design->size);
		printf("mod == %f\n", mod);
		printf("max_z == %d\n", design->max_z);
		printf("min_z == %d\n", design->min_z);
	}
	i++;
	if (i == (width))
	{
		printf("dif_z == %lld\n", dif_z);
		printf("width == %f\n", width);
		printf("width / 2 == %f\n", width / 2);
		printf("points[%i]: p->x == %f\n", i, p->x);
		printf("height == %f\n", height);
		printf("size == %i\n", design->size);
		printf("mod == %f\n", mod);
		printf("max_z == %d\n", design->max_z);
		printf("min_z == %d\n", design->min_z);
	}*/
