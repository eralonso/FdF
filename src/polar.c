/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:10:22 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/07 14:16:03 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_convert_rect(t_design *design, t_point *points, int size[2], \
		int iterator)
{
	int		iter[2];
	int		idx;

	iter[0] = 0;
	(void) design;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			points[idx].x = (points[idx].r + points[idx].z) \
			* sin(points[idx].fita) * cos(points[idx].fi);
			points[idx].y = (points[idx].r + points[idx].z) \
			* sin(points[idx].fita) * sin(points[idx].fi);
			points[idx].z = (points[idx].r + points[idx].z) \
			* cos(points[idx].fita);
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}

void	ft_polarize(t_design *design, t_point *points, int size)
{
	int		i;
	float	rad;

	i = -1;
	rad = design->info.width / (M_PI * 2);
	while (++i < size)
	{
		points[i].r = rad;
		points[i].fi = (-points[i].x * 2 * M_PI) / \
		((float)(design->info.width));
		points[i].fita = ((points[i].y + (design->info.height / 2)) * M_PI) / \
		((float)(design->info.height - 1));
	}
}
