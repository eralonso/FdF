/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:10:22 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/07 17:26:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_convert_rect(t_design *design, t_point *points, int size)
{
	int	i;

	i = -1;
	(void) design;
	while (++i < size)
	{
		points[i].x = (points[i].r + points[i].z) * sin(points[i].fita) \
		* cos(points[i].fi);
		points[i].y = (points[i].r + points[i].z) * sin(points[i].fita) \
		* sin(points[i].fi);
		points[i].z = (points[i].r + points[i].z) * cos(points[i].fita);
	}
}

void	ft_polarize(t_design *design, t_point *points, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		points[i].r = design->width / 2;
		points[i].fi = (-points[i].x * 2 * M_PI) / ((float)(design->width - 1));
		points[i].fita = ((points[i].y + (design->height / 2)) * M_PI) / \
		((float)(design->height - 2));
	}
}
