/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:53:00 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/13 17:17:26 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf_bonus.h>

int	ft_get_gradient(int start, int end, float len, float pos)
{
	float	dif[4];
	int		new[4];

	dif[0] = ((end >> 24) - (start >> 24)) / len;
	dif[1] = (((end >> 16) & 0xFF) - ((start >> 16) & 0xFF)) / len;
	dif[2] = (((end >> 8) & 0xFF) - ((start >> 8) & 0xFF)) / len;
	dif[3] = ((end & 0xFF) - (start & 0xFF)) / len;
	new[0] = (start >> 24) + (pos * dif[0]);
	new[1] = ((start >> 16) & 0xFF) + (pos * dif[1]);
	new[2] = ((start >> 8) & 0xFF) + (pos * dif[2]);
	new[3] = (start & 0xFF) + (pos * dif[3]);
	return ((int)(new[0] << 24) | (int)((new[1] << 16)) | (int)((new[2] << 8)) \
		| (int)(new[3]));
}

// Implement Opacity
	// float	opacity;
	// opacity = 1 - (new[0] / 0xFF);
	// return ((int)((new[1] << 16) * opacity) | (int)((new[2] << 8) * opacity)
	// 	| (int)(new[3] * opacity));

void	ft_set_color(t_design *design, t_point *p, int min_z, int max_z)
{
	if (p->hexa)
		return ;
	if (p->z < 0)
		p->color = ft_get_gradient(design->color.std, \
			design->color.btm, min_z, p->z);
	else if (p->z > 0)
		p->color = ft_get_gradient(design->color.std, \
			design->color.top, max_z, p->z);
	else
		p->color = design->color.std;
}

void	ft_pixel_put(t_pixmap *pixmap, int x, int y, int color)
{
	char	*pixel;
	int		rgb[4];

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = &pixmap->addr[(y * pixmap->line_len) + (x * pixmap->bytes_pp)];
	rgb[0] = color & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 16) & 0xFF;
	rgb[3] = color >> 24;
	pixel[0] = rgb[0];
	pixel[1] = rgb[1];
	pixel[2] = rgb[2];
	pixel[3] = rgb[3];
}

// Implement Opacity
	//float	opacity;
	//opacity = (float)(1 - ((float)((color >> 24) & 0xFF) / 0xFF));
	//opacity * rgb[0];
	//opacity * rgb[1];
	//opacity * rgb[2];

void	ft_put_density(t_design *design, t_point c, int density)
{
	int	x;
	int	y;

	y = -density;
	if (!design->event.shadow && design->event.sphere && c.z < 0)
		return ;
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
	t_point	inc;
	float	hip;
	float	len;

	if (!ft_valid_point(a) && !ft_valid_point(b))
		return ;
	hip = ft_module(b.x - a.x, b.y - a.y);
	c = a;
	len = hip;
	inc.x = (b.x - a.x) / hip;
	inc.y = (b.y - a.y) / hip;
	while (len > 0)
	{
		if (ft_valid_point(c))
		{
			c.color = ft_get_gradient(a.color, b.color, hip, hip - len);
			ft_put_density(design, c, density);
		}
		c.x += inc.x;
		c.y += inc.y;
		len--;
	}
}
