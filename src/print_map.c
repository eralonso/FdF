/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/19 11:26:59 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_print_axis(t_design *design)
{
	t_point axis_o;
	t_point	axis_x;
	t_point	axis_y;
	t_point	axis_z;
	int		multi;

	axis_o.x = 0; // 5 / 250
	axis_o.y = 0; // 3 / 150
	axis_o.z = 0;   // 0 / 0
	axis_x.x = 1; // 6 / 300
	axis_x.y = 0; // 3 / 150
	axis_x.z = 0;   // 0 / 0
	axis_y.x = 0; // 5 / 250
	axis_y.y = 1; // 4 / 200
	axis_y.z = 0;   // 0 / 0
	axis_z.x = 0; // 5 / 250
	axis_z.y = 0; // 3 / 150
	axis_z.z = 1;  // 1 / 50
	ft_rotate_z(&axis_o, design->angle[2]);
	ft_rotate_x(&axis_o, design->angle[0]);
	ft_rotate_y(&axis_o, design->angle[1]);
	ft_rotate_z(&axis_x, design->angle[2]);
	ft_rotate_x(&axis_x, design->angle[0]);
	ft_rotate_y(&axis_x, design->angle[1]);
	ft_rotate_z(&axis_y, design->angle[2]);
	ft_rotate_x(&axis_y, design->angle[0]);
	ft_rotate_y(&axis_y, design->angle[1]);
	ft_rotate_z(&axis_z, design->angle[2]);
	ft_rotate_x(&axis_z, design->angle[0]);
	ft_rotate_y(&axis_z, design->angle[1]);
	axis_o.z = 0;
	axis_x.z = 0;
	axis_y.z = 0;
	axis_z.z = 0;
	multi = 40;
	axis_o.x *= multi;
	axis_o.y *= multi;
	axis_x.x *= multi;
	axis_x.y *= multi;
	axis_y.x *= multi;
	axis_y.y *= multi;
	axis_z.x *= multi;
	axis_z.y *= multi;
	axis_o.x += (250 / 2);
	axis_o.y += (150 / 2);
	axis_x.x += (250 / 2);
	axis_x.y += (150 / 2);
	axis_y.x += (250 / 2);
	axis_y.y += (150 / 2);
	axis_z.x += (250 / 2);
	axis_z.y += (150 / 2);
	axis_o.color = WHITE;
	axis_x.color = RED;
	axis_y.color = BLUE;
	axis_z.color = GREEN;
	ft_print_line(axis_o, axis_x, design);
	ft_print_line(axis_o, axis_y, design);
	ft_print_line(axis_o, axis_z, design);
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

int	ft_print_map(t_design *design)
{
	int	i;
	int	j;
	int	k;

	design->copy = ft_copy_map(design->points, design->size);
	i = -1;
	while (++i < design->size)
		ft_config_point(&design->copy[i], design, design->width, design->height);
	i = -1;
	k = 0;
	while (++i < design->height)
	{
		j = -1;
		while (++j < design->width)
		{
			//printf("x == %i\n", j);
			//printf("Horizontal\n");
			//printf("k == %i\n", k);
			if (j < design->width - 1 && k + 1 < design->size)
				ft_print_line(design->copy[k], design->copy[k + 1], \
				design);
			//printf("Vertical\n\n\n");
			if (k + design->width < design->size)
				ft_print_line(design->copy[k], design->copy[k + \
				design->width], design);
			if (j < design->width - 1)
				k++;
		}
		k++;
	}
	ft_free((char **)&design->copy, 2);
	ft_print_axis(design);
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	return (1);
}

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

	if (!ft_valid_point(a) || !ft_valid_point(b))
		return ;
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
	hip = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	c.x = a.x;
	c.y = a.y;
	len = hip;
	//printf("Antes: len == %f\n\n", len);
	while (len > 0)
	{
		//printf("a.x: %f\n", a.x);
		//printf("b.x: %f\n", b.x);
		//printf("a.y: %f\n", a.y);
		//printf("b.y: %f\n", b.y);
		//printf("vuelta\n\n");
		ft_pixel_put(&design->pixmap, c.x, c.y, ft_get_gradient\
			(a.color, b.color, hip, hip - len));
		c.x += (b.x - a.x) / hip;
		c.y += (b.y - a.y) / hip;
		len--;
		//printf("len == %f\n", len);
	}
	//printf("Después\n\n");
}
