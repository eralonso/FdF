/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:57:35 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/05 10:50:20 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_scroll_zoom(int button, int x, int y, t_design *design)
{
	design->event.zoom.x = x - design->new_center[0];
	design->event.zoom.y = y - design->new_center[1];
	if (button == SCROLL_UP)
	{
		design->event.zoom.z *= (1 + (0.1 * (design->event.zoom.z < \
		(design->height * 10))));
		design->new_center[0] -= ((design->event.zoom.x * 1.1) - \
		(design->event.zoom.x));
		design->new_center[1] -= ((design->event.zoom.y * 1.1) - \
		(design->event.zoom.y));
	}
	else if (button == SCROLL_DOWN)
	{
		design->event.zoom.z /= (1 + (0.1 * (design->event.zoom.z > 0.000)));
		design->new_center[0] -= ((design->event.zoom.x / 1.1) - \
		design->event.zoom.x);
		design->new_center[1] -= ((design->event.zoom.y / 1.1) - \
		design->event.zoom.y);
	}
	ft_print_map(design);
}

int	ft_btn_press(int button, int x, int y, t_design *design)
{
	if (button == BUTTON_LEFT)
	{
		design->event.button_l.z = 1;
		design->event.button_l.x = x;
		design->event.button_l.y = y;
	}
	else if (button == BUTTON_RIGHT)
	{
		design->event.button_r.z = 1;
		design->event.button_r.x = x;
		design->event.button_r.y = y;
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
		design->event.button_l.z = 0;
	if (button == BUTTON_RIGHT)
		design->event.button_r.z = 0;
	return (0);
}
