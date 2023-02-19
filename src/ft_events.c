/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/19 12:13:26 by eralonso         ###   ########.fr       */
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
	if (key_code == KEY_ARROW_UP)
		design->angle[0] += 10;
	if (key_code == KEY_ARROW_DOWN)
		design->angle[0] -= 10;
	if (key_code == KEY_ARROW_LEFT)
		design->angle[1] += 10;
	if (key_code == KEY_ARROW_RIGHT)
		design->angle[1] -= 10;
	if (key_code == KEY_Q)
		design->angle[2] += 10;
	if (key_code == KEY_W)
		design->angle[2] -= 10;
	if (key_code == KEY_I || key_code == KEY_P || key_code == KEY_R || \
	(key_code >= KEY_ARROW_LEFT && key_code <= KEY_ARROW_UP) || \
	key_code == KEY_Q || key_code == KEY_W)
		ft_redraw(design);
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
	if (button == BUTTON_LEFT)
	{
		design->button_l.z = 1;
		design->button_l.x = x;
		design->button_l.y = y;
	}
	if (button == BUTTON_RIGHT)
	{
		design->button_r.z = 1;
		design->button_r.x = x;
		design->button_r.y = y;
	}
	if (button == SCROLL_UP)
		design->zoom *= 1.5;
	if (button == SCROLL_DOWN)
		design->zoom /= 1.5;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		ft_redraw(design);
	return (0);
}

int	ft_button_release(int button, int x, int y, t_design *design)
{
	(void) x;
	(void) y;
	if (button == BUTTON_LEFT)
		design->button_l.z = 0;
	if (button == BUTTON_RIGHT)
		design->button_r.z = 0;
	return (0);
}

int	ft_mouse_move(int x, int y, t_design *design)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (0);
	if (design->button_l.z)
	{
		design->angle[1] -= (int)design->button_l.x - x;
		design->angle[0] += (int)design->button_l.y - y;
		design->button_l.x = x;
		design->button_l.y = y;
		ft_print_map(design);
	}
	if (design->button_r.z)
	{
		design->shift.x -= (int)design->button_r.x - x;
		design->shift.y -= (int)design->button_r.y - y;
		design->button_r.x = x;
		design->button_r.y = y;
		ft_print_map(design);
	}
	ft_redraw(design);
	ft_print_cord(x, y, design);
	return (0);
}
