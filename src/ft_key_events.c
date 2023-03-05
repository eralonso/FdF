/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:56:50 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/05 19:46:56 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_key_press(int key_code, t_design *design)
{
	if (key_code == KEY_ESC)
		exit(ft_clean_design(design, 0));
	else if (key_code == KEY_CMD)
	{
		design->event.k_cmd = 1;
		design->event.sel_line.z = 1;
		design->event.sel_line.x = WIN_WIDTH / 2;
		design->event.sel_line.y = WIN_HEIGHT / 2;
	}
	else if (key_code == KEY_L)
		design->lines = !design->lines;
	else if (key_code == KEY_D)
		design->dots = !design->dots;
	else if (key_code == KEY_C)
		ft_restore_vars(design);
	else if (ft_change_view(key_code, design))
		return (0);
	else if (ft_change_angle(key_code, design))
		return (0);
	else if (ft_change_density(key_code, design))
		return (0);
	if (key_code == KEY_CMD || key_code == KEY_L || key_code == KEY_D \
		|| key_code == KEY_C)
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
