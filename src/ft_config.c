/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:33:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/22 19:07:18 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_rotate_x(t_point *p, float angle)
{
	float	y;
	float	z;
	float	rad;

	rad = (angle * M_PI) / 180;
	y = p->y;
	z = p->z;
	p->y = (y * cos(rad)) + (z * (-sin(rad)));
	p->z = (y * sin(rad)) + (z * cos(rad));
}

void	ft_rotate_y(t_point *p, float angle)
{
	float	x;
	float	z;
	float	rad;

	rad = (angle * M_PI) / 180;
	x = p->x;
	z = p->z;
	p->x = (x * cos(rad)) + (z * sin(rad));
	p->z = (x * (-sin(rad))) + (z * cos(rad));
}

void	ft_rotate_z(t_point *p, float angle)
{
	float	x;
	float	y;
	float	rad;

	rad = (angle * M_PI) / 180;
	x = p->x;
	y = p->y;
	p->x = (x * cos(rad)) + (y * (-sin(rad)));
	p->y = (x * sin(rad)) + (y * cos(rad));
}

float	ft_module(float x, float y)
{
	float	mod;

	mod = sqrt(pow(x, 2) + pow(y, 2));
	return (mod);
}

void	ft_zoom_in(t_point *p, t_design *design)
{
	if (design->zoom.x < 0)
	{
		p->x += -(design->zoom.x);// * 1.2);//design->zoom.z);
		//printf("NEG: p->zoom.x = %f\n", design->zoom.x);
	}
	if (design->zoom.x > 0)
	{
		p->x -= (design->zoom.x);// * 1.2);//design->zoom.z);
		//printf("POS: p->zoom.x = %f\n", design->zoom.x);
	}
	if (design->zoom.y < 0)
	{
		p->y += (design->zoom.y);// * 1.2);//design->zoom.z);
		//printf("NEG: p->zoom.y = %f\n", design->zoom.y);
	}
	if (design->zoom.y > 0)
	{
		p->y += (design->zoom.y);// * 1.2);//design->zoom.z);
		//printf("POS: p->zoom.y = %f\n", design->zoom.y);
	}
}

void	ft_zoom_out(t_point *p, t_design *design)
{
	if (design->zoom.x < 0)
		p->x += -(design->zoom.x);// * 1.2);//design->zoom.z);
	if (design->zoom.x > 0)
		p->x -= (design->zoom.x);// * 1.2);//design->zoom.z);
	if (design->zoom.y < 0)
		p->y += (design->zoom.y);// * 1.2);//design->zoom.z);
	if (design->zoom.y > 0)
		p->y += (design->zoom.y);// * 1.2);//design->zoom.z);
}

void	ft_config_point(t_point *p, t_design *design, float width, float height)
{
	float			mod;
	float			real_z;
	t_lli			dif_z;
	static int		sel = 0;
	static int		i = 0;
	//static int		j = 0;

	if (design->width - 15 <= p->x)
		sel = 0;
	real_z = p->z;
	mod = ft_module(width, height);
	dif_z = (design->max_z - design->min_z);
	dif_z = llabs(dif_z);
	//if (dif_z / width >= 0.5 && p->z != 0)// && p->z / dif_z > 0.1)
	//if (dif_z >> 1 > width || dif_z > height)
	if (dif_z >> 1 > width)
		p->z /= (dif_z >> 4);//((dif_z / width) * width);
	if (!i)
	{
		printf("dif_z == %lld\n", dif_z);
		printf("width == %f\n", width);
		printf("height == %f\n", height);
		printf("size == %i\n", design->size);
		printf("mod == %f\n", mod);
		printf("max_z == %d\n", design->max_z);
		printf("min_z == %d\n", design->min_z);
		i++;
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
	if (design->sel_line.z && !sel)
		sel = ft_point_selected(design, p);
}
