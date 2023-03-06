/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:10:22 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/06 19:16:04 by eralonso         ###   ########.fr       */
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
		points[i].x = (points[i].r + points[i].z) * sin(points[i].fita) * cos(points[i].fi);
		points[i].y = (points[i].r + points[i].z) * sin(points[i].fita) * sin(points[i].fi);
		points[i].z = (points[i].r + points[i].z) * cos(points[i].fita);
		//printf("x == %f && y == %f && z == %f\n", points[i].x, points[i].y, points[i].z);
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
		points[i].fita = ((points[i].y + (design->height / 2)) * M_PI) / ((float)(design->height - 1));
		/*if (points[i].y > 0)
			points[i].fita = (((points[i].y + (design->height / 2) - 1) * M_PI)) / ((float)(design->height - 1));
		else
			points[i].fita = (((points[i].y + (design->height / 2) - 1) * M_PI)) / ((float)(design->height - 1));
		points[i].fi = ((points[i].x + (design->width / 2)) * 2 * M_PI) / ((float)(design->width - 1));*/
		//printf("r == %f && fi == %f && fita == %f\n", points[i].r, points[i].fi, points[i].fita);
	}
	//printf("\n\n");
}
