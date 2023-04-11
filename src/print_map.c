/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/11 16:24:46 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>
#include	<time.h>

void	ft_put_map(t_point *points, t_design *design);

int	ft_print_map(t_design *design)
{
	clock_t	t;

	t = clock();
	design->copy = ft_copy_map(design->points, design->info.size, \
	design->info.inc_x);
	if (!design->copy)
		return (ft_clean_design(design, 0));
	ft_config_points(design->copy, design->info, design);
	ft_print_background(design);
	ft_put_map(design->copy, design);
	ft_print_axis(design);
	ft_free((char **)&design->copy, 2);
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	if (design->event.show_menu)
		ft_print_menu(design);
	design->render = (float)(((double)(clock() - t) / CLOCKS_PER_SEC) * 1000);
	return (1);
}

void	ft_check_line(t_point *points, t_design *design, int idx, int inc[2])
{
	if (idx + inc[0] < design->info.size && design->points[idx].y == \
	design->points[idx + inc[0]].y && design->prop.lines)
		ft_print_line(points[idx], points[idx + inc[0]], design, \
		design->prop.density);
	if (idx + inc[1] < design->info.size && design->prop.lines)
		ft_print_line(points[idx], points[idx + inc[1]], \
		design, design->prop.density);
}
	// int	j;
	// int	inc_x;
	// int	inc_y;

	// j = 0;
	// inc_x = design->info.inc_x;
	// inc_y = design->info.inc_y;
	// while (j < design->info.width)
	// {
	// 	j += inc[0];
	// 	i += inc[0];
	// }

void	ft_put_map(t_point *points, t_design *design)
{
	int	size[2];
	int	iterator[2];
	int	iter[2];
	int	idx;

	size[0] = design->info.width;
	size[1] = design->info.height;
	iterator[0] = design->info.inc_x;
	iterator[1] = design->info.inc_y;
	iter[0] = 0;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			ft_check_line(points, design, idx, iterator);
			if (design->prop.dots)
				ft_put_density(design, points[idx], \
				ft_round(design->prop.density * 1.5));
			iter[1] += iterator[0];
		}
		iter[0] += iterator[0];
	}
	ft_check_sphere(points, design, size, iterator);
}

void	ft_print_axis(t_design *design)
{
	t_point	axis[4];
	float	config[2];
	int		size[2];

	size[0] = 4;
	size[1] = 1;
	ft_init_axis(axis);
	ft_rotate_z(axis, design->prop.angle[2], size, 1);
	ft_rotate_x(axis, design->prop.angle[0], size, 1);
	ft_rotate_y(axis, design->prop.angle[1], size, 1);
	config[0] = 40;
	config[1] = 40;
	ft_scale(axis, config, size, 1);
	config[0] = WIN_WIDTH - 125;
	config[1] = 75;
	ft_traslate(axis, config, size, 1);
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
	t_point	p;

	p.y = -1;
	while (++(p.y) <= WIN_HEIGHT)
	{
		p.x = -1;
		while (++(p.x) <= WIN_WIDTH)
		{
			if (design->event.show_menu && p.x < (WIN_WIDTH / 5))
				ft_pixel_put(&design->pixmap, p.x, p.y, design->color.menu);
			else
				ft_pixel_put(&design->pixmap, p.x, p.y, design->color.bckg);
		}
	}
}
