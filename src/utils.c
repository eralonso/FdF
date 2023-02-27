/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:35:12 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/27 18:48:55 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_error(char *str, char *file, int err)
{
	if (str)
		ft_printf(1, "%s\n", str);
	else if (err && file)
	{
		ft_printf(1, "FdF: %s: ", file);
		perror("");
	}
	else if (err)
		perror("Error: ");
	return (err);
}

int	ft_valid_point(t_point p)
{
	if (p.x < 0 || p.x >= WIN_WIDTH || p.y < 0 || p.y >= WIN_HEIGHT)
		return (0);
	return (1);
}

void	ft_pixel_put(t_pixmap *pixmap, int x, int y, int color)
{
	char	*pixel;
	float	opacity;
	int		rgb[4];

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = pixmap->addr + (y * pixmap->line_len + x * (pixmap->bpp / 8));
	rgb[0] = color & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 16) & 0xFF;
	opacity = (float)(1 - ((float)((color >> 24) & 0xFF) / 0xFF));
	pixel[0] = ft_round(opacity * rgb[0]);
	pixel[1] = ft_round(opacity * rgb[1]);
	pixel[2] = ft_round(opacity * rgb[2]);
}

int	ft_clean_design(t_design *design, int num)
{
	ft_free((char **)&(design->points), 2);
	ft_free(&design->map, 2);
	return (num);
}

int	ft_close_program(void *param)
{
	t_design	*design;

	design = (t_design *)param;
	mlx_destroy_image(design->mlx, design->pixmap.img);
	mlx_destroy_window(design->mlx, design->mlx_win);
	ft_clean_design(design, 0);
	exit(0);
	return (1);
}
