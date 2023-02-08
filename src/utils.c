/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:35:12 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/08 13:28:46 by eralonso         ###   ########.fr       */
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
		perror("");
	return (err);
}

void	ft_pixel_put(t_pixmap *pixmap, int x, int y, int color)
{
	char	*dst;

	dst = pixmap->addr + (y * pixmap->line_length + x * (pixmap->bpp / 8));
	*(unsigned int *)dst = color;
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
	return (1);
}
