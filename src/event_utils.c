/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:29:07 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/27 12:46:39 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_print_cord(int x, int y, t_design *design)
{
	char	*cord_x;
	char	*cord_y;

	cord_x = ft_itoa(x - (WIN_WIDTH / 2));
	cord_y = ft_itoa(-(y - (WIN_HEIGHT / 2)));
	mlx_clear_window(design->mlx, design->mlx_win);
	mlx_put_image_to_window(design->mlx, design->mlx_win, \
	design->pixmap.img, 0, 0);
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
	design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, \
	&design->pixmap.bpp, &design->pixmap.line_len, &design->pixmap.endian);
	ft_print_map(design);
}

int	ft_change_view(int key_code, t_design *design)
{
	if (key_code == KEY_I)
		ft_isometric(design);
	else if (key_code == KEY_P)
		ft_parallel(design);
	else if (key_code == KEY_T)
		ft_top(design);
	else if (key_code == KEY_R)
		ft_reverse(design);
	else if (key_code == KEY_X)
		design->angle[0] += 180;
	else if (key_code == KEY_Y)
		design->angle[1] += 180;
	else if (key_code == KEY_Z)
		design->angle[2] += 180;
	if (key_code == KEY_I || key_code == KEY_P || key_code == KEY_R || \
		key_code == KEY_T || key_code == KEY_X || key_code == KEY_Y || \
		key_code == KEY_Z)
	{
		design->zoom.z = 1;
		design->zoom.x = 0;
		design->zoom.y = 0;
		design->shift.x = 0;
		design->shift.y = 0;
		ft_print_map(design);
		return (1);
	}
	return (0);
}

int	ft_change_angle(int key_code, t_design *design)
{
	if (key_code == KEY_ARROW_UP)
		design->angle[0] += 10;
	else if (key_code == KEY_ARROW_DOWN)
		design->angle[0] -= 10;
	else if (key_code == KEY_ARROW_LEFT)
		design->angle[1] -= 10;
	else if (key_code == KEY_ARROW_RIGHT)
		design->angle[1] += 10;
	else if (key_code == KEY_Q)
		design->angle[2] -= 10;
	else if (key_code == KEY_W)
		design->angle[2] += 10;
	if ((key_code >= KEY_ARROW_LEFT && key_code <= KEY_ARROW_UP) || \
	key_code == KEY_Q || key_code == KEY_W)
	{
		ft_print_map(design);
		return (1);
	}
	return (0);
}

int	ft_change_density(int key_code, t_design *design)
{
	if (key_code == KEY_S)
		design->density -= (design->density > 0);
	else if (key_code == KEY_D)
		design->density++;
	if (key_code == KEY_S || key_code == KEY_D)
	{
		ft_print_map(design);
		return (1);
	}
	return (0);
}
