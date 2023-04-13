/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:56:50 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/13 18:45:08 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf_bonus.h>

void	ft_change_visibility(int key_code, t_design *design)
{
	if (key_code == KEY_L)
		design->prop.lines = !design->prop.lines;
	else if (key_code == KEY_D)
		design->prop.dots = !design->prop.dots;
	else if (key_code == KEY_S)
		design->event.shadow = !design->event.shadow;
	else if (key_code == KEY_H)
	{
		design->event.show_menu = !design->event.show_menu;
		if (!design->event.show_menu)
			design->prop.new_center[0] -= (MENU_WIDTH / 2);
		else
			design->prop.new_center[0] += (MENU_WIDTH / 2);
	}
	else if (key_code == KEY_C)
	{
		design->prop.new_center[0] = WIN_WIDTH / 2;
		if (design->event.show_menu)
			design->prop.new_center[0] = MENU_WIDTH + \
			((WIN_WIDTH - MENU_WIDTH) / 2);
		design->prop.new_center[1] = WIN_HEIGHT / 2;
	}
	if (key_code == KEY_L || key_code == KEY_D || key_code == KEY_S || \
		key_code == KEY_H || key_code == KEY_C)
		ft_print_map(design);
}

void	ft_change_palette(int key_code, t_design *design)
{
	if (key_code == KEY_1)
		design->color = design->palette.def;
	else if (key_code == KEY_2)
		design->color = design->palette.real;
	else if (key_code == KEY_3)
		design->color = design->palette.neon;
	else if (key_code == KEY_4)
		design->color = design->palette.bw;
	else if (key_code == KEY_5)
		design->color = design->palette.wb;
	if ((key_code >= KEY_1 && key_code <= KEY_4) || key_code == KEY_5)
	{
		design->color.menu = GRAY;
		ft_color(design);
		ft_print_map(design);
	}
}

void	ft_change_z_div(int key_code, t_design *design)
{
	int			high_z;

	if (design->info.max_z - design->info.min_z < 0)
		high_z = abs(design->info.min_z);
	else
		high_z = abs(design->info.max_z);
	if (key_code == KEY_SUM && design->prop.lim_z < 10)
	{
		design->prop.z_div /= 1.5;
		design->prop.lim_z++;
	}
	else if (key_code == KEY_RES && design->prop.z_div <= high_z)
	{
		design->prop.z_div *= 1.5;
		design->prop.lim_z--;
	}
	if (design->prop.z_div < 0)
		design->prop.z_div = 1;
	if (key_code == KEY_SUM || key_code == KEY_RES)
		ft_print_map(design);
}

int	ft_key_press(int key_code, t_design *design)
{
	if (key_code == KEY_ESC)
		exit(ft_clean_design(design, 0));
	else if (key_code == KEY_R)
		ft_restore_vars(design);
	else if (key_code == KEY_CMD)
	{
		design->event.k_cmd = 1;
		design->event.sel_line.z = 1;
	}
	ft_change_view(key_code, design);
	ft_change_angle(key_code, design);
	ft_change_density(key_code, design);
	ft_change_visibility(key_code, design);
	ft_change_palette(key_code, design);
	ft_change_z_div(key_code, design);
	if (key_code == KEY_CMD || key_code == KEY_R)
		ft_print_map(design);
	return (0);
}

int	ft_key_release(int key_code, t_design *design)
{
	if (key_code == KEY_CMD)
	{
		design->event.k_cmd = 0;
		design->event.sel_line.z = 0;
		ft_print_map(design);
	}
	return (0);
}
