/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:55:21 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/05 11:14:52 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_button_l_move(int x, int y, t_design *design)
{
	if (design->event.button_l.z == 2)
	{
		design->event.button_l.x = x;
		design->event.button_l.y = y;
		design->event.button_l.z = 1;
	}
	if (design->event.button_l.z)
	{
		design->angle[1] -= ((float)((int)design->event.button_l.x - x) / 5);
		design->angle[0] += ((float)((int)design->event.button_l.y - y) / 5);
		design->event.button_l.x = x;
		design->event.button_l.y = y;
	}
}

void	ft_button_r_move(int x, int y, t_design *design)
{
	float	tmp_x;
	float	tmp_y;

	if (design->event.button_r.z == 2)
	{
		design->event.button_r.x = x;
		design->event.button_r.y = y;
		design->event.button_r.z = 1;
	}
	if (design->event.button_r.z)
	{
		tmp_x = design->event.shift.x;
		tmp_y = design->event.shift.y;
		design->event.shift.x -= (int)design->event.button_r.x - x;
		design->event.shift.y -= (int)design->event.button_r.y - y;
		design->event.button_r.x = x;
		design->event.button_r.y = y;
		design->new_center[0] += (design->event.shift.x - tmp_x);
		design->new_center[1] += (design->event.shift.y - tmp_y);
	}
}

int	ft_mouse_move(int x, int y, t_design *design)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
	{
		if (design->event.button_l.z)
			design->event.button_l.z = 2;
		if (design->event.button_r.z)
			design->event.button_r.z = 2;
		return (0);
	}
	if (design->event.k_cmd)
	{
		design->event.sel_line.z = 1;
		design->event.sel_line.x = x;
		design->event.sel_line.y = y;
		ft_print_map(design);
	}
	if (design->event.button_l.z || design->event.button_r.z)
	{
		ft_button_l_move(x, y, design);
		ft_button_r_move(x, y, design);
		ft_print_map(design);
	}
	return (0);
}
