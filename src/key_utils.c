/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:29:07 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/10 12:44:10 by eralonso         ###   ########.fr       */
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

void	ft_restore_vars(t_design *design)
{
	t_lli	dif_z;

	dif_z = design->info.max_z - design->info.min_z;
	dif_z = llabs(dif_z);
	ft_isometric(design);
	design->event.zoom.z = 1;
	design->event.zoom.x = 0;
	design->event.zoom.y = 0;
	design->event.shift.x = 0;
	design->event.shift.y = 0;
	design->prop.new_center[0] = WIN_WIDTH / 2;
	design->prop.new_center[1] = WIN_HEIGHT / 2;
	design->prop.lines = 1;
	design->prop.dots = 0;
	design->prop.density = 1;
	design->prop.z_div = 1;
	if (dif_z / 32 >= 1)
		design->prop.z_div = (design->event.scale * ((float)dif_z / 64));
	design->event.sphere = 0;
	design->event.shadow = 0;
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
	else if (key_code == KEY_G)
		design->event.sphere = !design->event.sphere;
	else if (key_code == KEY_X)
		design->prop.angle[0] += 180;
	else if (key_code == KEY_Y)
		design->prop.angle[1] += 180;
	else if (key_code == KEY_Z)
		design->prop.angle[2] += 180;
	if (key_code == KEY_I || key_code == KEY_P || key_code == KEY_R || \
		key_code == KEY_T || key_code == KEY_X || key_code == KEY_Y || \
		key_code == KEY_Z || key_code == KEY_G)
	{
		ft_print_map(design);
		return (1);
	}
	return (0);
}

int	ft_change_angle(int key_code, t_design *design)
{
	if (key_code == KEY_ARROW_UP)
		design->prop.angle[0] += 10;
	else if (key_code == KEY_ARROW_DOWN)
		design->prop.angle[0] -= 10;
	else if (key_code == KEY_ARROW_LEFT)
		design->prop.angle[1] -= 10;
	else if (key_code == KEY_ARROW_RIGHT)
		design->prop.angle[1] += 10;
	else if (key_code == KEY_Q)
		design->prop.angle[2] -= 10;
	else if (key_code == KEY_W)
		design->prop.angle[2] += 10;
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
	if (key_code == KEY_V && design->prop.density > 0)
		design->prop.density--;
	else if (key_code == KEY_B && design->prop.density < 5)
		design->prop.density++;
	if (key_code == KEY_V || key_code == KEY_B)
	{
		ft_print_map(design);
		return (1);
	}
	return (0);
}
