/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:33:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/20 18:59:19 by eralonso         ###   ########.fr       */
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

void	ft_config_point(t_point *p, t_design *design, float width, float height)
{
	float			mod;
	float			real_z;
	long			dif_z;
	//static float	div = 1;

	(void) design;
	real_z = p->z;
	//mod = sqrt(pow(width, 2) + pow(height, 2));
	mod = ft_module(width, height);
	dif_z = fabs((double)design->max_z - design->min_z);
	//if (div == 1)
	//{
	//	while (((dif_z / width) * div) >=  WIN_HEIGHT)
	//		div++;
	//}
	//p->z /= div;
	if (dif_z / height >= 1)
		p->z /= ((dif_z / height) * (WIN_HEIGHT / mod));
	//printf("Real z: %f || Div z: %f\n", real_z, p->z);
	//Vista Isométrica
	//printf("design->angle[0] == %f\n", design->angle[0]);
	//printf("design->angle[1] == %f\n", design->angle[1]);
	//printf("design->angle[2] == %f\n", design->angle[2]);
	ft_rotate_z(p, design->angle[2]);
	ft_rotate_x(p, design->angle[0]);
	ft_rotate_y(p, design->angle[1]);
	//Vista paralela
	//ft_rotate_z(p, 0);
	//ft_rotate_x(p, 90);
	//ft_rotate_y(p, 0);
	p->z = real_z;
	//if (mod < 1080)
	//{
		p->x = (p->x * (WIN_HEIGHT / mod)) * design->zoom;
		p->y = (p->y * (WIN_HEIGHT / mod)) * design->zoom;
	//}
	//if (width < 1920 / 2)
	//	p->x *= ((1920 / width) / 3);
	//else
	//	p->x /= 2;
	//if (height < 1080 / 2)
	//	p->y *= ((1080 / height) / 3);
	//else
	//	p->y /= 2;
	p->x = (p->x + (WIN_WIDTH / 2)) + design->shift.x;
	p->y = (p->y + (WIN_HEIGHT / 2)) + design->shift.y;
	//p->x = ((p->x + ((1920 - (width - (p->x * 2))) * 1)));
	//p->y = ((p->y + ((1080 - (height - (p->y * 2))) * 1)));
}
