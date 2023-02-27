/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/27 19:13:37 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

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

t_point	*ft_copy_map(t_point *points, int size)
{
	t_point	*copy;
	int		i;

	copy = ft_calloc(sizeof(t_point), size + 1);
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < size)
		copy[i] = points[i];
	return (copy);
}

void	ft_put_map(t_point *points, t_design *design)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < design->height)
	{
		j = -1;
		while (++j < design->width)
		{
			if (j < design->width - 1 && k + 1 < design->size)
				ft_print_line(points[k], points[k + 1], \
				design, design->density);
			if (k + design->width < design->size)
				ft_print_line(points[k], points[k + \
				design->width], design, design->density);
			if (j < design->width - 1)
				k++;
		}
		k++;
	}
}

int	ft_print_map(t_design *design)
{
	design->copy = ft_copy_map(design->points, design->size);
	ft_config_points(design->copy, design);
	ft_print_background(design);
	ft_put_map(design->copy, design);
	ft_free((char **)&design->copy, 2);
	ft_print_axis(design);
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	return (1);
}

void	ft_put_density(t_design *design, t_point c, int density)
{
	int	x;
	int	y;

	y = -density;
	while (++y < density)
	{
		x = -density;
		while (++x < density)
			ft_pixel_put(&design->pixmap, c.x + x, c.y + y, c.color);
	}
}

void	ft_print_line(t_point a, t_point b, t_design *design, int density)
{
	t_point	c;
	float	hip;
	float	len;

	if (!ft_valid_point(a) && !ft_valid_point(b))
		return ;
	hip = ft_module(b.x - a.x, b.y - a.y);
	c.x = a.x;
	c.y = a.y;
	len = hip + 1;
	while (--len > 0)
	{
		if (ft_valid_point(c))
		{
			c.color = ft_get_gradient(a.color, b.color, hip, hip - len);
			ft_put_density(design, c, density);
		}
		c.x += (b.x - a.x) / hip;
		c.y += (b.y - a.y) / hip;
	}
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
