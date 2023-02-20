/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:53:00 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/20 18:30:39 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int ft_get_gradient(int start, int end, float len, float pos)
{
	float	dif[3];
	int		new[3];

	dif[0] = ((end >> 16) - (start >> 16)) / len;
	dif[1] = (((end >> 8) & 0xFF) - ((start >> 8) & 0xFF)) \
			 / len;
	dif[2] = ((end & 0xFF) - (start & 0xFF)) \
			 / len;
	new[0] = (start >> 16) + (pos * dif[0]);
	new[1] = ((start >> 8) & 0xFF) + (pos * dif[1]);
	new[2] = (start & 0xFF) + (pos * dif[2]);
	return ((new[0] << 16) + (new[1] << 8) + new[2]);
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
