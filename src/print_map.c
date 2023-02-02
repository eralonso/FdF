/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/02 19:46:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_print_map(t_design *design)
{
	int	i;
	int	x;
	int	y;

	design->mlx = mlx_init();
	design->mlx_win = mlx_new_window(design->mlx, 1920, 1080, "FdF eralonso");
	design->pixmap.img = mlx_new_image(design->mlx, 1920, 1080);
	design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, \
	&design->pixmap.bpp, &design->pixmap.line_length, &design->pixmap.endian);
	i = -1;
	while (++i < design->width * design->height)
	{
		x = -1;
		while (++x < 50)
			my_mlx_pixel_put(&design->pixmap, (design->points[i].x * 50) + x, 0 + (design->points[i].y * 50), 0XFFFFFFFF);
		my_mlx_pixel_put(&design->pixmap, 0 + (design->points[i].x * 50), 0 + (design->points[i].y * 50), 0X00FF0000);
	}
	i = -1;
	while (++i < design->width * design->height)
	{
		y = -1;
		while (++y < 50)
			my_mlx_pixel_put(&design->pixmap, (design->points[i].x * 50), y + (design->points[i].y * 50), 0xFFFFFFFF);
		my_mlx_pixel_put(&design->pixmap, 0 + (design->points[i].x * 50), 50 * design->points[i].y, 0X00FF0000);
	}
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	mlx_loop(design->mlx);
	return (1);
}
