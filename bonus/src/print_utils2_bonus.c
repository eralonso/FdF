/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:55:37 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/13 17:17:36 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <fdf_bonus.h>

void	ft_init_axis(t_point axis[4])
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		axis[i].x = 0;
		axis[i].y = 0;
		axis[i].z = 0;
	}
	axis[1].x = 1;
	axis[2].y = 1;
	axis[3].z = 1;
}

void	ft_check_sphere(t_point *points, t_design *design, int size[2], \
		int iterator[2])
{
	int	iter[2];
	int	inc;
	int	idx;

	(void) size;
	if (design->event.sphere && design->prop.lines)
	{
		inc = (design->info.width - 1) - ((design->info.width - 1) \
				% iterator[0]);
		iter[0] = 0;
		while (iter[0] < design->info.size)
		{
			idx = iter[0];
			ft_print_line(points[idx], points[idx + inc], \
			design, design->prop.density);
			iter[0] += iterator[1];
		}
	}
}

void	ft_calculate_incs(t_design *design)
{
	int	inc;

	inc = 4 / design->event.scale;
	design->info.inc_x = 1;
	design->info.inc_y = design->info.width;
	if (design->event.scale <= 4)
	{
		design->info.inc_x = inc;
		design->info.inc_y = design->info.width * inc;
	}
}
