/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:13:13 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/08 13:34:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_rotate_x(t_point *points, float angle, int size)
{
	t_point	p;
	float	rad;
	int		i;
	double	sinus;
	double	cosinus;

	rad = (angle * M_PI) / 180;
	sinus = sin(rad);
	cosinus = cos(rad);
	i = -1;
	while (++i < size)
	{
		p = points[i];
		points[i].y = (p.y * cosinus) + (p.z * (-sinus));
		points[i].z = (p.y * sinus) + (p.z * cosinus);
	}
}

void	ft_rotate_y(t_point *points, float angle, int size)
{
	t_point	p;
	float	rad;
	int		i;
	double	sinus;
	double	cosinus;

	rad = (angle * M_PI) / 180;
	sinus = sin(rad);
	cosinus = cos(rad);
	i = -1;
	while (++i < size)
	{
		p = points[i];
		points[i].x = (p.x * cosinus) + (p.z * sinus);
		points[i].z = (p.x * (-sinus)) + (p.z * cosinus);
	}
}

void	ft_rotate_z(t_point *points, float angle, int size)
{
	t_point	p;
	float	rad;
	int		i;
	double	sinus;
	double	cosinus;

	rad = (angle * M_PI) / 180;
	sinus = sin(rad);
	cosinus = cos(rad);
	i = -1;
	while (++i < size)
	{
		p = points[i];
		points[i].x = (p.x * cosinus) + (p.y * (-sinus));
		points[i].y = (p.x * sinus) + (p.y * cosinus);
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
