/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:27 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_key_press(int key_code, t_design *design)
{
	if (key_code == KEY_ESC)
		exit(ft_clean_design(design, 0));
	if (key_code == KEY_P)
		ft_parallel(design);
	if (key_code == KEY_I)
		ft_isometric(design);
	if (key_code == KEY_R)
		ft_neutral(design);
	if (key_code == KEY_I || key_code == KEY_P || key_code == KEY_R)
	{
		mlx_destroy_image(design->mlx, design->pixmap.img);
		design->pixmap.img = mlx_new_image(design->mlx, \
		WIN_WIDTH, WIN_HEIGHT);
		design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, &design\
		->pixmap.bpp, &design->pixmap.line_len, &design->pixmap.endian);
		ft_print_map(design);
	}
	return (0);
}

int	ft_key_release(int key_code, t_design *design)
{
	(void) key_code;
	(void) design;
	return (0);
}

int	ft_button_press(int button, int x, int y, t_design *design)
{
	(void) x;
	(void) y;
	(void) button;
	(void) design;
	return (0);
}

int	ft_button_release(int button, int x, int y, t_design *design)
{
	(void) x;
	(void) y;
	(void) button;
	(void) design;
	return (0);
}

int	ft_mouse_move(int x, int y, t_design *design)
{
	char	*cord_x;
	char	*cord_y;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (0);
	cord_x = ft_itoa(x);
	cord_y = ft_itoa(y);
	mlx_clear_window(design->mlx, design->mlx_win);
	ft_print_map(design);
	mlx_string_put(design->mlx, design->mlx_win, 250, 10, 0XFFFFFF, cord_x);
	mlx_string_put(design->mlx, design->mlx_win, 250, 50, 0xFFFFFF, cord_y);
	ft_free(&cord_x, 2);
	ft_free(&cord_y, 2);
	return (0);
}
