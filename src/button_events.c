/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:57:35 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/10 12:17:53 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_scroll_zoom(int button, int x, int y, t_design *design)
{
	design->event.zoom.x = x - design->prop.new_center[0];
	design->event.zoom.y = y - design->prop.new_center[1];
	if (button == SCROLL_UP && design->event.zoom.z <= design->info.width)
	{
		design->event.zoom.z *= (1 + 0.05);
		// printf("zoom: %f\n", design->event.zoom.z);
		design->prop.new_center[0] -= ((design->event.zoom.x * 1.05) - \
		(design->event.zoom.x));
		design->prop.new_center[1] -= ((design->event.zoom.y * 1.05) - \
		(design->event.zoom.y));
	}
	else if (button == SCROLL_DOWN && design->event.zoom.z > 0.00)
	{
		design->event.zoom.z /= (1 + 0.05);
		design->prop.new_center[0] -= ((design->event.zoom.x / 1.05) - \
		design->event.zoom.x);
		design->prop.new_center[1] -= ((design->event.zoom.y / 1.05) - \
		design->event.zoom.y);
	}
	ft_print_map(design);
}

int	ft_btn_press(int button, int x, int y, t_design *design)
{
	if (button == BUTTON_LEFT)
	{
		design->event.btn_l.z = 1;
		design->event.btn_l.x = x;
		design->event.btn_l.y = y;
		if (design->event.k_cmd)
		{
			design->event.put_pt = 1;
			ft_print_map(design);
		}
	}
	else if (button == BUTTON_RIGHT)
	{
		design->event.btn_r.z = 1;
		design->event.btn_r.x = x;
		design->event.btn_r.y = y;
		// if (design->event.put_pt)
		// {
		// 	design->event.put_pt = 0;
		// 	ft_print_map(design);	
		// }
	}
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		ft_scroll_zoom(button, x, y, design);
	return (0);
}

int	ft_btn_release(int button, int x, int y, t_design *design)
{
	(void) x;
	(void) y;
	if (button == BUTTON_LEFT)
		design->event.btn_l.z = 0;
	if (button == BUTTON_RIGHT)
		design->event.btn_r.z = 0;
	return (0);
}
