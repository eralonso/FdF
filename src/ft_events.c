/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/20 12:28:07 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_key_press(int key_code, t_design *design)
{
	if (key_code == KEY_ESC)
		exit(ft_clean_design(design, 0));
	ft_change_view(key_code, design);
	ft_change_angle(key_code, design);
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
		design->zoom *= 1.2;
	if (button == SCROLL_DOWN)
		design->zoom /= 1.2;
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
	{
		if (design->button_l.z)
			design->button_l.z = 2;
		if (design->button_r.z)
			design->button_r.z = 2;
		return (0);
	}
	if (design->button_l.z == 2)
	{
		design->button_l.x = x;
		design->button_l.y = y;
		design->button_l.z = 1;
	}
	if (design->button_r.z == 2)
	{
		design->button_r.x = x;
		design->button_r.y = y;
		design->button_r.z = 1;
	}
	if (design->button_l.z)
	{
		design->angle[1] -= ((float)((int)design->button_l.x - x) / 5);
		design->angle[0] += ((float)((int)design->button_l.y - y) / 5);
		design->button_l.x = x;
		design->button_l.y = y;
	}
	if (design->button_r.z)
	{
		design->shift.x -= (int)design->button_r.x - x;
		design->shift.y -= (int)design->button_r.y - y;
		design->button_r.x = x;
		design->button_r.y = y;
	}
	ft_redraw(design);
	ft_print_cord(x, y, design);
	return (0);
}
