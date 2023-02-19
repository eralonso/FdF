/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:29:07 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/19 11:56:34 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_print_cord(int x, int y, t_design *design)
{
	char	*cord_x;
	char	*cord_y;

	cord_x = ft_itoa(x);
	cord_y = ft_itoa(y);
	mlx_clear_window(design->mlx, design->mlx_win);
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
	//ft_print_map(design);
	mlx_string_put(design->mlx, design->mlx_win, 250, 10, 0XFFFFFF, cord_x);
	mlx_string_put(design->mlx, design->mlx_win, 250, 50, 0xFFFFFF, cord_y);
	ft_free(&cord_x, 2);
	ft_free(&cord_y, 2);
}

void	ft_redraw(t_design *design)
{
	mlx_destroy_image(design->mlx, design->pixmap.img);
	design->pixmap.img = mlx_new_image(design->mlx, \
	WIN_WIDTH, WIN_HEIGHT);
	design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, &design\
	->pixmap.bpp, &design->pixmap.line_len, &design->pixmap.endian);
	ft_print_map(design);
}
