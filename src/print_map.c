/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/09 15:52:24 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_print_map(t_design *design)
{
	int	i;

	i = -1;
	while (++i < design->size)
	{
		if (design->points[i].x + 1 < (float)design->width / 2)
			ft_print_line(design->points[i], design->points[i + 1], \
			design);
		if (design->points[i].y + 1 < (float)design->height / 2)
			ft_print_line(design->points[i], design->points[i + \
			design->width], design);
	}
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	return (1);
}

void	ft_config_point(t_point *p, int view, float width, float height)
{
	int		x;
	int		y;
	float	angle[2];

	x = p->x;
	y = p->y;
	if (view == ISOMETRIC)
	{
		angle[0] = (30 * M_PI) / 180;
		angle[1] = (30 * M_PI) / 180;
	}
	else
	{
		angle[0] = (view * M_PI) / 180;
		angle[1] = (view * M_PI) / 180;
	}
	p->x = (x * cos(angle[0])) - (y * sin(angle[0]));
	p->y = (x * sin(angle[1])) + (y * cos(angle[1])) - p->z;
	p->x = ((p->x + ((1920 - (width - (p->x * 2))) * 1)));
	p->y = ((p->y + ((1080 - (height - (p->y * 2))) * 1)));
	if (width < 1920 / 2)
		p->x *= (1920 / width) / 2;
	//else
	//	p->x /= 2;
	if (height < 1080 / 2)
		p->y *= (1080 / height) / 2;
	//else
	//	p->y /= 2;
}

void	ft_print_line(t_point a, t_point b, t_design *design)
{
	t_point	c;
	float	hip;
	float	len;

	ft_config_point(&a, ISOMETRIC, design->width, design->height);
	ft_config_point(&b, ISOMETRIC, design->width, design->height);
	if (a.x < 0 || a.x > 1920 || a.y < 0 || a.y > 1080 || b.x < 0 \
	|| b.x > 1920 || b.y < 0 || b.y > 1080)
		return ;
	hip = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	c.x = a.x;
	c.y = a.y;
	len = hip;
	while (len > 0)
	{
		if ((!a.hexa && a.z > 0) || (!b.hexa && b.z > 0))
			a.color = 0x00FF0000;
		else if ((!a.hexa && a.z < 0) || (!b.hexa && b.z < 0))
			a.color = 0x000000FF;
		ft_pixel_put(&design->pixmap, c.x, c.y, a.color);
		c.x += (b.x - a.x) / hip;
		c.y += (b.y - a.y) / hip;
		len--;
	}
}
