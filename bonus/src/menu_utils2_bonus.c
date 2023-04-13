/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:09:01 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/13 17:16:56 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf_bonus.h>

void	put_square(t_design *design, int *cords, int size, int color)
{
	int	i;

	i = cords[0] + (CHAR_PX * 2);
	while (i < (cords[0] + (CHAR_PX * 2)) + size)
	{
		mlx_string_put(design->mlx, design->mlx_win, i, cords[1], \
						color, "|");
		i++;
	}
}

void	put_axis(t_design *design, int *cords, float axis[3], int angle)
{
	put_str(design, cords, 0, "[ X Y Z ] = [");
	if (angle)
		put_nbr(design, cords, 0, (int)axis[0] % 360);
	else
		put_nbr(design, cords, 0, axis[0]);
	if (angle)
		put_nbr(design, cords, 0, (int)axis[1] % 360);
	else
		put_nbr(design, cords, 0, axis[1]);
	if (angle)
		put_nbr(design, cords, 0, (int)axis[2] % 360);
	else
		put_nbr(design, cords, 0, axis[2]);
	put_str(design, cords, 1, "]");
}
