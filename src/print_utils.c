/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:53:00 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/27 11:47:40 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int ft_get_gradient(int start, int end, float len, float pos)
{
	float	dif[4];
	int		new[4];

	dif[0] = ((end >> 24) - (start >> 24)) / len;
	dif[1] = (((end >> 16) & 0xFF) - ((start >> 16) & 0xFF)) / len;
	dif[2] = (((end >> 8) & 0xFF) - ((start >> 8) & 0xFF)) / len;
	dif[3] = ((end & 0xFF) - (start & 0xFF))  / len;
	new[0] = (start >> 24) + (pos * dif[0]);
	new[1] = ((start >> 16) & 0xFF) + (pos * dif[1]);
	new[2] = ((start >> 8) & 0xFF) + (pos * dif[2]);
	new[3] = (start & 0xFF) + (pos * dif[3]);
	return ((new[0] << 24) | (new[1] << 16) | (new[2] << 8) | new[3]);
}

void	ft_set_color(t_design *design, t_point *p, int min_z, int max_z)
{
	if (p->hexa)
		return ;
	if (p->z < 0)
		p->color = ft_get_gradient(design->color.std, \
			design->color.btm, min_z, p->z);
	else if (p->z > 0)
		p->color = ft_get_gradient(design->color.std, \
			design->color.top, max_z, p->z);
	else
		p->color = design->color.std;
}
