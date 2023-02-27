/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/27 19:29:21 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_key_press(int key_code, t_design *design)
{
	if (key_code == KEY_ESC)
		exit(ft_clean_design(design, 0));
	if (key_code == KEY_CMD)
	{
		design->k_cmd = 1;
		design->sel_line.z = 1;
		design->sel_line.x = WIN_WIDTH / 2;
		design->sel_line.y = WIN_HEIGHT / 2;
		ft_print_map(design);
	}
	if (ft_change_view(key_code, design))
		return (0);
	else if (ft_change_angle(key_code, design))
		return (0);
	else if (ft_change_density(key_code, design))
		return (0);
	return (0);
}

int	ft_key_release(int key_code, t_design *design)
{
	if (key_code == KEY_CMD)
	{
		design->k_cmd = 0;
		design->sel_line.z = 0;
		ft_print_map(design);
	}
	return (0);
}

void	ft_scroll_zoom(int button, int x, int y, t_design *design)
{
	if (button == SCROLL_UP)
	{
		design->zoom.z *= (1 + (0.2 * (design->zoom.z < \
		(design->height * 10))));
		design->zoom.color = 1;
	}
	else if (button == SCROLL_DOWN)
	{
		design->zoom.z /= (1 + (0.2 * (design->zoom.z > 0.000)));
		design->zoom.color = 2;
	}
	design->zoom.x = x - (WIN_WIDTH / 2);
	design->zoom.y = y - (WIN_HEIGHT / 2);
	printf("SCROLL: design->zoom.x == %f && design->zoom.y == %f\n", \
	design->zoom.x, design->zoom.y);
	ft_print_map(design);
}

int	ft_btn_press(int button, int x, int y, t_design *design)
{
	if (button == BUTTON_LEFT)
	{
		design->button_l.z = 1;
		design->button_l.x = x;
		design->button_l.y = y;
	}
	else if (button == BUTTON_RIGHT)
	{
		design->button_r.z = 1;
		design->button_r.x = x;
		design->button_r.y = y;
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
		design->button_l.z = 0;
	if (button == BUTTON_RIGHT)
		design->button_r.z = 0;
	return (0);
}

void	ft_button_l_move(int x, int y, t_design *design)
{
	if (design->button_l.z == 2)
	{
		design->button_l.x = x;
		design->button_l.y = y;
		design->button_l.z = 1;
	}
	if (design->button_l.z)
	{
		design->angle[1] -= ((float)((int)design->button_l.x - x) / 5);
		design->angle[0] += ((float)((int)design->button_l.y - y) / 5);
		design->button_l.x = x;
		design->button_l.y = y;
	}
}

void	ft_button_r_move(int x, int y, t_design *design)
{
	if (design->button_r.z == 2)
	{
		design->button_r.x = x;
		design->button_r.y = y;
		design->button_r.z = 1;
	}
	if (design->button_r.z)
	{
		design->shift.x -= (int)design->button_r.x - x;
		design->shift.y -= (int)design->button_r.y - y;
		design->button_r.x = x;
		design->button_r.y = y;
	}
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
	if (design->k_cmd)
	{
		design->sel_line.z = 1;
		design->sel_line.x = x;
		design->sel_line.y = y;
		ft_print_map(design);
	}
	if (design->button_l.z || design->button_r.z)
	{
		ft_button_l_move(x, y, design);
		ft_button_r_move(x, y, design);
		ft_print_map(design);
	}
	return (0);
}
