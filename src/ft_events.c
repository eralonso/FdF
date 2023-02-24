/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/24 13:56:11 by eralonso         ###   ########.fr       */
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
		design->sel_line.z = -1;
		design->sel_line.x = 0;
		design->sel_line.y = 0;
		ft_redraw(design);
	}
	ft_change_view(key_code, design);
	ft_change_angle(key_code, design);
	return (0);
}

int	ft_key_release(int key_code, t_design *design)
{
	if (key_code == KEY_CMD)
	{
		design->k_cmd = 0;
		design->sel_line.z = 0;
		ft_redraw(design);
	}
	return (0);
}

int	ft_point_selected(t_design *design, t_point *p, int restart)
{
	static float	max_dif_acul = FLT_MAX;
	float	dif_x;
	float	dif_y;
	float	max_dif;
	float	mod;

	dif_x = design->sel_line.x - p->x;
	dif_y = design->sel_line.y - p->y;
	//dif_x = fabs(dif_x);
	//dif_y = fabs(dif_y);
	mod = ft_module(design->width, design->height);
	max_dif = ((WIN_HEIGHT - design->height) / mod) * design->zoom.z;
	//printf("max_dif == %f\n", max_dif);
	//printf("dif_x == %f\n", dif_x);
	//printf("dif_y == %f\n", dif_y);
	//if (dif_x < (max_dif / 2) && dif_y < (max_dif / 2) && )
	if (ft_module(dif_x, dif_y) < (max_dif) && ft_module(dif_x, dif_y) < max_dif_acul)
	{
		max_dif_acul = ft_module(dif_x, dif_y);
		//printf("modulo == %f\n", ft_module(dif_x, dif_y));
		//printf("p->x == %f\n", p->x);
		//printf("p->y == %f\n", p->y);
		//printf("desig->sel_line.z == %f\n", design->sel_line.z);
		design->sel_line.z += 1;
		p->select = design->sel_line.z;
		printf("p->select == %f\n", p->select);
		return (1);
	}
	if (restart)
	{
		printf("Restart de max_dif_acul\n");
		max_dif_acul = FLT_MAX;
	}
	return (0);
}

int	ft_btn_press(int button, int x, int y, t_design *design)
{
	/*if (button == BUTTON_LEFT && design->k_cmd)
	{
		design->sel_line.z = 1;
		design->sel_line.x = x;
		design->sel_line.y = y;
		ft_redraw(design);
	}*/
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
		design->zoom.z *= 1.2;
	if (button == SCROLL_DOWN)
		design->zoom.z /= 1.2;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		design->zoom.x = x - (WIN_WIDTH / 2);
		design->zoom.y = y - (WIN_HEIGHT / 2);
		printf("SCROLL: design->zoom.x == %f && design->zoom.y == %f\n", \
		design->zoom.x, design->zoom.y);
		ft_redraw(design);
	}
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

int	ft_mouse_move(int x, int y, t_design *design)
{
	if (design->k_cmd)
	{
		design->sel_line.z = -1;
		design->sel_line.x = x;
		design->sel_line.y = y;
		ft_redraw(design);
	}
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
	if (design->button_l.z || design->button_r.z)
		ft_redraw(design);
	//ft_print_cord(x, y, design);
	return (0);
}
