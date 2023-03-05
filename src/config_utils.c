/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:13:13 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/02 16:15:47 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_rotate_x(t_point *points, float angle, int size)
{
	float	y;
	float	z;
	float	rad;
	int		i;

	rad = (angle * M_PI) / 180;
	i = -1;
	while (++i < size)
	{
		y = points[i].y;
		z = points[i].z;
		points[i].y = (y * cos(rad)) + (z * (-sin(rad)));
		points[i].z = (y * sin(rad)) + (z * cos(rad));
	}
}

void	ft_rotate_y(t_point *points, float angle, int size)
{
	float	x;
	float	z;
	float	rad;
	int		i;

	rad = (angle * M_PI) / 180;
	i = -1;
	while (++i < size)
	{
		x = points[i].x;
		z = points[i].z;
		points[i].x = (x * cos(rad)) + (z * sin(rad));
		points[i].z = (x * (-sin(rad))) + (z * cos(rad));
	}
}

void	ft_rotate_z(t_point *points, float angle, int size)
{
	float	x;
	float	y;
	float	rad;
	int		i;

	rad = (angle * M_PI) / 180;
	i = -1;
	while (++i < size)
	{
		x = points[i].x;
		y = points[i].y;
		points[i].x = (x * cos(rad)) + (y * (-sin(rad)));
		points[i].y = (x * sin(rad)) + (y * cos(rad));
	}
}

void	ft_scale(t_point *points, float x, float y, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		points[i].x *= x;
		points[i].y *= y;
	}
}

void	ft_traslate(t_point *points, float x, float y, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		points[i].x += x;
		points[i].y += y;
	}
}
