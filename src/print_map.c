/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/07 10:50:11 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_put_map(t_point *points, t_design *design);

int	ft_print_map(t_design *design)
{
	design->copy = ft_copy_map(design->points, design->size);
	if (!design->copy)
		return (ft_clean_design(design, 0));
	ft_config_points(design->copy, design);
	ft_print_background(design);
	ft_print_axis(design);
	ft_put_map(design->copy, design);
	design->current = ft_copy_map(design->copy, design->size);
	if (!design->current)
		return (ft_clean_design(design, 0));
	ft_free((char **)&design->copy, 2);
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	return (1);
}

void	ft_put_map(t_point *points, t_design *design)
{
	int	i;

	i = -1;
	while (++i < design->size)
	{
		if (i + 1 < design->size && design->points[i].y == \
		design->points[i + 1].y && design->lines)
			ft_print_line(points[i], points[i + 1], design, design->density);
		if (i + design->width < design->size && design->lines)
			ft_print_line(points[i], points[i + \
			design->width], design, design->density);
		if (design->dots)
			ft_put_density(design, points[i], ft_round(design->density * 1.5));
	}
}

void	ft_print_axis(t_design *design)
{
	t_point	axis[4];
	int		i;

	i = -1;
	while (++i < 4)
	{
		axis[i].x = 0;
		axis[i].y = 0;
		axis[i].z = 0;
	}
	axis[1].x = 1;
	axis[2].y = 1;
	axis[3].z = 1;
	ft_rotate_z(axis, design->angle[2], 4);
	ft_rotate_x(axis, design->angle[0], 4);
	ft_rotate_y(axis, design->angle[1], 4);
	ft_scale(axis, 40, 40, 4);
	ft_traslate(axis, WIN_WIDTH - 125, 75, 4);
	axis[0].color = WHITE;
	axis[1].color = RED;
	axis[2].color = BLUE;
	axis[3].color = GREEN;
	ft_print_line(axis[0], axis[1], design, 2);
	ft_print_line(axis[0], axis[2], design, 2);
	ft_print_line(axis[0], axis[3], design, 2);
}

void	ft_print_background(t_design *design)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= WIN_HEIGHT)
	{
		x = -1;
		while (++x <= WIN_WIDTH)
			ft_pixel_put(&design->pixmap, x, y, design->color.bckg);
	}
}
