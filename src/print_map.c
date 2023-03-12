/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/12 19:16:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>
#include	<time.h>

void	ft_put_map(t_point *points, t_design *design);

int	ft_print_map(t_design *design)
{
	clock_t	time;

	time = clock();
	design->copy = ft_copy_map(design->points, design->size);
	if (!design->copy)
		return (ft_clean_design(design, 0));
	ft_config_points(design->copy, design);
	ft_print_background(design);
	ft_print_axis(design);
	ft_put_map(design->copy, design);
	ft_free((char **)&design->copy, 2);
	printf("Render: %f\n", ((double)(clock() - time) / CLOCKS_PER_SEC) * 1000);
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	return (1);
}

void	ft_check_sphere(t_point *points, t_design *design)
{
	int	i;

	i = 0;
	if (design->event.sphere && design->lines)
	{
		while (i < design->size)
		{
			ft_print_line(points[i], points[i + design->width - 1], \
			design, design->density);
			i += design->width;
		}
	}
}

void	ft_put_line_dots(t_point *points, t_design *design, int i)
{
	int	j;

	j = 0;
	while (j < design->width)
	{
		if (i + design->inc_x < design->size && design->points[i].y == \
		design->points[i + design->inc_x].y && design->lines)
			ft_print_line(points[i], points[i + design->inc_x], design, \
			design->density);
		if (i + design->inc_y < design->size && design->lines)
			ft_print_line(points[i], points[i + \
			design->inc_y], design, design->density);
		if (design->dots)
			ft_put_density(design, points[i], ft_round(design->density * 1.5));
		j += design->inc_x;
		i += design->inc_x;
	}
}

void	ft_put_map(t_point *points, t_design *design)
{
	int	i;

	i = 0;
	while (i < design->size)
	{
		ft_put_line_dots(points, design, i);
		i += design->inc_y;
	}
	ft_check_sphere(points, design);
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
