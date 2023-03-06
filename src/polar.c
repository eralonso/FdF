/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:10:22 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/06 13:26:14 by eralonso         ###   ########.fr       */
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
		points[i].x = points[i].r * cos(points[i].fi);
		points[i].y = points[i].r * cos(points[i].fita);
		points[i].z = points[i].r * cos(points[i].fi) * cos(points[i].fita);
	}
}

void	ft_polarize(t_design *design, t_point *points, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		points[i].r = points[i].z;
		points[i].fita = ((points[i].y * M_PI) / 2) / (design->height / 2);
		points[i].fi = (points[i].x * M_PI) / (design->width / 2);
	}
}
