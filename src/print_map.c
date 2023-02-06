/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/06 12:48:44 by eralonso         ###   ########.fr       */
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

void	ft_config_point(t_point *p, float angle, float width, float height)
{
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = (x * cos(angle)) - (y * sin(angle));
	p->y = (x * sin(angle)) + (y * cos(angle));
	p->x = ((p->x + ((1920 - width) / 2))); //(width * 2.3)) * 20);
	p->y = ((p->y + ((1080 - height) / 2))); //(height * 2)) * 20);
	p->x += p->x * 0.5;
	p->y += p->y * 0.5;
}

void	ft_print_line(t_point a, t_point b, t_design *design)
{
	float	x;
	float	y;
	float	hip;
	float	len;
	float	angle;

//	printf("a.x == %f\n", a.x);
//	printf("a.y == %f\n", a.y);
//	printf("b.x == %f\n", b.x);
//	printf("b.y == %f\n", b.y);
//	printf("a.x == %f\n", a.x);
//	printf("a.y == %f\n", a.y);
//	printf("b.x == %f\n", b.x);
//	printf("b.y == %f\n", b.y);
	//x = a.x;
	//y = a.y;
	//a.x = (x * cos(15)) - (y * sin(15));
	//a.y = (x * sin(15)) + (y * cos(15));
	//x = b.x;
	//y = b.y;
	//b.x = (x * cos(15)) - (y * sin(15));
	//b.y = (x * sin(15)) + (y * cos(15));
	//a.x = ((a.x + (design->width * 2.3)) * 20);
	//a.y = ((a.y + (design->height * 2)) * 20);
	//b.x = ((b.x + (design->width * 2.3)) * 20);
	//b.y = ((b.y + (design->height * 2)) * 20);
	angle = 30  * M_PI / 180;
	printf("Angulo == %f\n\n", angle);
	ft_config_point(&a, angle, design->width, design->height);
	ft_config_point(&b, angle, design->width, design->height);
	hip = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	//hip = sqrt(pow(((b.x + design->width) * 50) - ((a.x + design->width) * 50), 2) \
	//+ pow(((b.y + design->height) * 50) - ((a.y + design->height) * 50), 2));
	//x = ((a.x + design->width) * cos(120) - (a.y + design->height) * sin(120)) * 50 ;
	//y = ((a.x + design->width) * sin(120) + (a.y + design->height) * cos(120)) * 50;
	x = a.x;
	y = a.y;
	//printf("hip == %f\n", hip);
	//printf("x == %f\n", x);
	//printf("y == %f\n", y);
	printf("a.x == %f\n", a.x);
	printf("a.y == %f\n", a.y);
	//printf("b.x == %f\n", b.x);
	//printf("b.y == %f\n", b.y);
	len = hip;
	while (len > 0)
	{
		//printf("hip == %f\n", hip);
		//printf("x == %f\n", x);
		//printf("y == %f\n", y);
		ft_pixel_put(&design->pixmap, x, y, a.color);
		//x += (((b.x + design->width) * 50) - ((a.x + design->width) * 50)) / hip;
		//y += (((b.y + design->height) * 50) - ((a.y + design->height) * 50)) / hip;
		x += (b.x - a.x) / hip;
		y += (b.y - a.y) / hip;
		len--;
	}
}
