/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/07 10:24:16 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_print_map(t_design *design)
{
	int	i;

	i = -1;
	while (++i < design->width * design->height)
	{
		if (design->points[i].x + 1 < design->width / 2)
			ft_print_line(design->points[i], design->points[i + 1], \
			design);
		if (design->points[i].y + 1 < design->height / 2)
			ft_print_line(design->points[i], design->points[i + \
			(int)design->width], design);
	}
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	return (1);
}

void	ft_config_point(t_point *p, int	view, float width, float height)
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
	p->y = (x * sin(angle[1])) + (y * cos(angle[1]));
	if (width < 1920 / 2)
		p->x *= (1920 / width) / 2;
	if (height < 1080 / 2)
		p->y *= (1080 / height) / 2;
	p->x = ((p->x + ((1920 - (width - (x * 10))) / 2)));
	p->y = ((p->y + ((1080 - (height - (y * 10))) / 2)));
}

void	ft_print_line(t_point a, t_point b, t_design *design)
{
	float	x;
	float	y;
	float	hip;
	float	len;

	ft_config_point(&a, ISOMETRIC, design->width, design->height);
	ft_config_point(&b, ISOMETRIC, design->width, design->height);
	if (a.x < 0 || a.x > 1920 || a.y < 0 || a.y > 1080 || b.x < 0 \
	|| b.x > 1920 || b.y < 0 || b.y > 1080)
		return ;
	hip = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	x = a.x;
	y = a.y;
	//printf("a.x == %f\n", a.x);
	//printf("a.y == %f\n", a.y);
	len = hip;
	while (len > 0)
	{
		ft_pixel_put(&design->pixmap, x, y, a.color);
		x += (b.x - a.x) / hip;
		y += (b.y - a.y) / hip;
		len--;
	}
}
