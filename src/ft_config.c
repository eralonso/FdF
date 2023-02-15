/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:33:45 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/15 18:37:00 by eralonso         ###   ########.fr       */
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

void	ft_config_point(t_point *p, t_design *design, float width, float height)
{
	float			mod;
	float			real_z;
	float			dif_z;
	//static float	div = 0;

	(void) design;
	real_z = p->z;
	mod = sqrt(pow(width, 2) + pow(height, 2));
	dif_z = design->max_z - design->min_z;
	/*if (!div)
	{
		while (dif_z > ((height * sin(45)) / 2))
		{
			div++;
			printf("dif_z == %f\n", dif_z);
			printf("div == %f\n", div);
			printf("height == %f\n", height);
			printf("sin(45) == %f\n", sin(45));
			printf("mod == %f\n", mod);
			printf("height * sin(45) == %f\n\n", height * sin(45));
			dif_z /= div;
		}
	}
	*/
	//p->z /= div;
	//Vista Isométrica
	ft_rotate_z(p, 45);
	ft_rotate_x(p, 45);
	ft_rotate_y(p, 0);
	//Vista paralela
	//ft_rotate_z(p, 0);
	//ft_rotate_x(p, 90);
	//ft_rotate_y(p, 0);
	p->z = real_z;
	if (mod < 1080)
	{
		p->x *= (1080 / mod);
		p->y *= (1080 / mod);
	}
	//if (width < 1920 / 2)
	//	p->x *= ((1920 / width) / 3);
	//else
	//	p->x /= 2;
	//if (height < 1080 / 2)
	//	p->y *= ((1080 / height) / 3);
	//else
	//	p->y /= 2;
	p->x += ((1920 / 2));
	p->y += ((1080 / 2));
	//p->x = ((p->x + ((1920 - (width - (p->x * 2))) * 1)));
	//p->y = ((p->y + ((1080 - (height - (p->y * 2))) * 1)));
}
