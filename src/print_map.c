/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/03 13:42:18 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>
void	ft_print_line(t_point a, t_point b, t_design *design, int color);

int	ft_print_map(t_design *design)
{
	int	i;

	design->mlx = mlx_init();
	design->mlx_win = mlx_new_window(design->mlx, 1920, 1080, "FdF eralonso");
	design->pixmap.img = mlx_new_image(design->mlx, 1920, 1080);
	design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, \
	&design->pixmap.bpp, &design->pixmap.line_length, &design->pixmap.endian);
	i = -1;
	while (++i < design->width * design->height)
	{
		if (design->points[i].x + 1 < design->width / 2)
			ft_print_line(design->points[i], design->points[i + 1], design, design->points[i].color);
		if (design->points[i].y + 1 < design->height / 2)
			ft_print_line(design->points[i], design->points[i + (int)design->width], \
			design, design->points[i].color);
	}
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	mlx_loop(design->mlx);
	return (1);
}

/*
int	ft_print_map(t_design *design)
{
	int	i;
	//int	x;
	//int	y;

	design->mlx = mlx_init();
	design->mlx_win = mlx_new_window(design->mlx, 1920, 1080, "FdF eralonso");
	design->pixmap.img = mlx_new_image(design->mlx, 1920, 1080);
	design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, \
	&design->pixmap.bpp, &design->pixmap.line_length, &design->pixmap.endian);
	i = -1;
	while (++i < design->width * design->height)
	{
		if (design->points[i].x + 1 < design->width / 2)
			ft_print_line(design->points[i], design->points[i + 1], design, design->points[i].color);
		//x = -1;
		//while (design->points[i].x < design->width / 2 - 1 && ++x < 50)
		//	my_mlx_pixel_put(&design->pixmap, ((design->points[i].x + design->width) * 50) + x, \
		//	0 + ( (design->points[i].y + design->height) * 50), 0XFFFFFFFF);
		my_mlx_pixel_put(&design->pixmap, 0 + ((design->points[i].x + design->width) * 50), \
		0 + ((design->points[i].y + design->height) * 50), 0X00FF0000);
	}
	i = -1;
	while (++i < design->width * design->height)
	{
		if (design->points[i].y + 1 < design->height / 2)
			ft_print_line(design->points[i], design->points[i + (int)design->width], \
			design, design->points[i].color);
		//y = -1;
		//while (design->points[i].y < design->height / 2 - 1 && ++y < 50)
		//	my_mlx_pixel_put(&design->pixmap, ((design->points[i].x + design->width) * 50), \
		//	y + ((design->points[i].y + design->height) * 50), 0xFFFFFFFF);
		my_mlx_pixel_put(&design->pixmap, 0 + ((design->points[i].x + design->width) * 50), \
		50 * (design->points[i].y + design->height), 0X00FF0000);
	}
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	mlx_loop(design->mlx);
	return (1);
}
*/

void	ft_print_line(t_point a, t_point b, t_design *design, int color)
{
	float	x;
	float	y;
	float	hip;
	float	len;

	printf("a.x == %f\n", a.x);
	printf("a.y == %f\n", a.y);
	printf("b.x == %f\n", b.x);
	printf("b.y == %f\n", b.y);
	printf("a.x == %f\n", a.x);
	printf("a.y == %f\n", a.y);
	printf("b.x == %f\n", b.x);
	printf("b.y == %f\n", b.y);
	x = a.x;
	y = a.y;
	a.x = (x * cos(120)) - (y * sin(120));
	a.y = (x * sin(120)) + (y * cos(120));
	x = b.x;
	y = b.y;
	b.x = (x * cos(120)) - (y * sin(120));
	b.y = (x * sin(120)) + (y * cos(120));
	a.x = ((a.x + design->width) * 30);
	a.y = ((a.y + design->height) * 30);
	b.x = ((b.x + design->width) * 30);
	b.y = ((b.y + design->height) * 30);
	hip = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	//hip = sqrt(pow(((b.x + design->width) * 50) - ((a.x + design->width) * 50), 2) \
	//+ pow(((b.y + design->height) * 50) - ((a.y + design->height) * 50), 2));
	//x = ((a.x + design->width) * cos(120) - (a.y + design->height) * sin(120)) * 50 ;
	//y = ((a.x + design->width) * sin(120) +  (a.y + design->height) * cos(120)) * 50;
	x = a.x;
	y = a.y;
	printf("hip == %f\n", hip);
	printf("x == %f\n", x);
	printf("y == %f\n", y);
	printf("a.x == %f\n", a.x);
	printf("a.y == %f\n", a.y);
	printf("b.x == %f\n", b.x);
	printf("b.y == %f\n", b.y);
	len = hip;
	while (len > 0)
	{
		//printf("hip == %f\n", hip);
		//printf("x == %f\n", x);
		//printf("y == %f\n", y);
		my_mlx_pixel_put(&design->pixmap, x, y, color);
		//x += (((b.x + design->width) * 50) - ((a.x + design->width) * 50)) / hip;
		//y += (((b.y + design->height) * 50) - ((a.y + design->height) * 50)) / hip;
		x += (b.x - a.x) / hip;
		y += (b.y - a.y) / hip;
		len--;
	}
}
