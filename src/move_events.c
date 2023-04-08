/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:55:21 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/05 10:37:06 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_button_l_move(int x, int y, t_design *design)
{
	if (design->event.btn_l.z == 2)
	{
		design->event.btn_l.x = x;
		design->event.btn_l.y = y;
		design->event.btn_l.z = 1;
	}
	if (design->event.btn_l.z)
	{
		design->prop.angle[1] -= ((float)((int)design->event.btn_l.x - x) / 5);
		design->prop.angle[0] += ((float)((int)design->event.btn_l.y - y) / 5);
		design->event.btn_l.x = x;
		design->event.btn_l.y = y;
	}
}

void	ft_button_r_move(int x, int y, t_design *design)
{
	float	tmp_x;
	float	tmp_y;

	if (design->event.btn_r.z == 2)
	{
		design->event.btn_r.x = x;
		design->event.btn_r.y = y;
		design->event.btn_r.z = 1;
	}
	if (design->event.btn_r.z)
	{
		tmp_x = design->event.shift.x;
		tmp_y = design->event.shift.y;
		design->event.shift.x -= (int)design->event.btn_r.x - x;
		design->event.shift.y -= (int)design->event.btn_r.y - y;
		design->event.btn_r.x = x;
		design->event.btn_r.y = y;
		design->prop.new_center[0] += (design->event.shift.x - tmp_x);
		design->prop.new_center[1] += (design->event.shift.y - tmp_y);
	}
}

int	ft_mouse_move(int x, int y, t_design *design)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
	{
		if (design->event.btn_l.z)
			design->event.btn_l.z = 2;
		if (design->event.btn_r.z)
			design->event.btn_r.z = 2;
		return (0);
	}
	if (design->event.k_cmd)
	{
		design->event.sel_line.z = 1;
		design->event.sel_line.x = x;
		design->event.sel_line.y = y;
		ft_print_map(design);
	}
	if (design->event.btn_l.z || design->event.btn_r.z)
	{
		ft_button_l_move(x, y, design);
		ft_button_r_move(x, y, design);
		ft_print_map(design);
	}
	return (0);
}
