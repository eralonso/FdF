/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:55:37 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/09 18:48:00 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <fdf.h>

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
		printf("inc: %i\n", inc);
		iter[0] = 0;
		while (iter[0] < design->info.size)
		{
			idx = iter[0];
			ft_print_line(points[idx], points[idx + inc], \
			design, design->prop.density);
			iter[0] += iterator[1];
		}
		printf("iter[0]: %i\n", iter[0]);
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
/*
	printf("design->info.inc_x == %i && design->info.inc_y
	== %i\n", design->info.inc_x, design->info.inc_y);
*/

// void	ft_draw_dot(t_point *points, t_design *design, int size[2],
//		int iterator)
// {
// 	t_point	p;
// 	int		r;
// 	int		iter[2];

// 	iter[0] = 0;
// 	r = design->prop.density;
// 	while (iter[0] < size[1])
// 	{
// 		iter[1] = 0;
// 		while (iter[1] < size[0])
// 		{
// 			p = points[iter[1] + (size[0] * iter[0])];
// 			iter[1] += iterator;
// 		}	
// 		iter[0] += iterator;
// 	}
// }