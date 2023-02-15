/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/15 19:33:32 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_key_press(int key_code, t_design *design)
{
	if (key_code == KEY_ESC)
		exit(ft_clean_design(design, 0));
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
	//char	*tmp;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (0);
	cord_x = ft_itoa(x);
	cord_y = ft_itoa(y);
	//tmp = cord_x;
	//cord_x = ft_strjoin("X: \0", cord_x);
	//ft_free(&tmp, 2);
	//tmp = cord_y;
	//cord_x = ft_strjoin("y: \0", cord_y);
	//ft_free(&tmp, 2);
	mlx_string_put(design->mlx, design->mlx_win, 250, 10, 0XFFFFFF, cord_x);
	mlx_string_put(design->mlx, design->mlx_win, 250, 50, 0xFFFFFF, cord_y);
	ft_free(&cord_x, 2);
	ft_free(&cord_y, 2);
	return (0);
}
