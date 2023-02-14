/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/14 12:43:27 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_print_map(t_design *design)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < design->size)
		ft_config_point(&design->points[i], design, design->width, design->height);
	i = -1;
	k = 0;
	while (++i < design->height)
	{
		j = -1;
		while (++j < design->width)
		{
			if (j < design->width - 1 && k + 1 < design->size)
				ft_print_line(design->points[k], design->points[k + 1], \
				design);
			if (k + design->width < design->size)
				ft_print_line(design->points[k], design->points[k + \
				design->width], design);
			if (j < design->width - 1)
				k++;
		}
		k++;
	}
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	return (1);
}

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
	ft_rotate_z(p, 45);
	ft_rotate_x(p, 45);
	ft_rotate_y(p, 0);
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

/*
int	ft_get_gradient(int start, int end, float hip)
{
	int	result = 0;

	result = start;
	if (start - end > 0)
		result -= ((start - end) / hip);
	else if (start - end < 0)
		result += ((end - start) / hip);
	return (result);
}
*/

int ft_get_gradient(int start, int end, float len, float pos)
{
	float	dif[3];
	int		new[3];

	dif[0] = ((end >> 16) - (start >> 16)) / len;
	dif[1] = (((end >> 8) & 0xFF) - ((start >> 8) & 0xFF)) \
			 / len;
	dif[2] = ((end & 0xFF) - (start & 0xFF)) \
			 / len;
	new[0] = (start >> 16) + (pos * dif[0]);
	new[1] = ((start >> 8) & 0xFF) + (pos * dif[1]);
	new[2] = (start & 0xFF) + (pos * dif[2]);
	return ((new[0] << 16) + (new[1] << 8) + new[2]);
}

void	ft_print_line(t_point a, t_point b, t_design *design)
{
	t_point	c;
	float	hip;
	float	len;

	c.z = a.z;
	c.hexa = a.hexa | b.hexa;
	if (!b.hexa && b.z < 0)
		b.color = BLUE;
	else if (!b.hexa && b.z > 0)
		b.color = RED;
	if (!a.hexa && a.z < 0)
		a.color = BLUE;
	else if (!a.hexa && a.z > 0)
		a.color = RED;
	if (a.x < 0 || a.x > 1920 || a.y < 0 || a.y > 1080 || b.x < 0 \
	|| b.x > 1920 || b.y < 0 || b.y > 1080)
		return ;
	hip = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	c.x = a.x;
	c.y = a.y;
	len = hip;
	while (len > 0)
	{
		ft_pixel_put(&design->pixmap, c.x, c.y, ft_get_gradient\
			(a.color, b.color, hip, hip - len));
		c.x += (b.x - a.x) / hip;
		c.y += (b.y - a.y) / hip;
		len--;
	}
}
