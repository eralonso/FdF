/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:13:13 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/11 16:27:39 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_rotate_x(t_point *points, float angle, int size[2], int iterator)
{
	float	y;
	float	z;
	float	rad;
	int		iter[2];
	int		idx;

	rad = (angle * M_PI) / 180;
	iter[0] = 0;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			y = points[idx].y;
			z = points[idx].z;
			points[idx].y = (y * cos(rad)) + (z * (-sin(rad)));
			points[idx].z = (y * sin(rad)) + (z * cos(rad));
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}

void	ft_rotate_y(t_point *points, float angle, int size[2], int iterator)
{
	float	x;
	float	z;
	float	rad;
	int		iter[2];
	int		idx;

	rad = (angle * M_PI) / 180;
	iter[0] = 0;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			x = points[idx].x;
			z = points[idx].z;
			points[idx].x = (x * cos(rad)) + (z * sin(rad));
			points[idx].z = (x * (-sin(rad))) + (z * cos(rad));
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}

void	ft_rotate_z(t_point *points, float angle, int size[2], int iterator)
{
	float	x;
	float	y;
	float	rad;
	int		iter[2];
	int		idx;

	rad = (angle * M_PI) / 180;
	iter[0] = 0;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			x = points[idx].x;
			y = points[idx].y;
			points[idx].x = (x * cos(rad)) + (y * (-sin(rad)));
			points[idx].y = (x * sin(rad)) + (y * cos(rad));
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}

void	ft_scale(t_point *points, float axis[2], int size[2], int iterator)
{
	int	iter[2];
	int	idx;

	iter[0] = 0;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			points[idx].x *= axis[0];
			points[idx].y *= axis[1];
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}

void	ft_traslate(t_point *points, float axis[2], int size[2], int iterator)
{
	int	iter[2];
	int	idx;

	iter[0] = 0;
	while (iter[0] < size[1])
	{
		iter[1] = 0;
		while (iter[1] < size[0])
		{
			idx = iter[1] + (size[0] * iter[0]);
			points[idx].x += axis[0];
			points[idx].y += axis[1];
			iter[1] += iterator;
		}
		iter[0] += iterator;
	}
}
