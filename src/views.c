/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:10:39 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/21 18:09:24 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_isometric(t_design *design)
{
	design->angle[0] = 45;
	design->angle[1] = 0;
	design->angle[2] = 45;
}

void	ft_parallel(t_design *design)
{
	design->angle[0] = 90;
	design->angle[1] = 0;
	design->angle[2] = 0;
}

void	ft_top(t_design *design)
{
	design->angle[0] = 0;
	design->angle[1] = 0;
	design->angle[2] = 0;
}

void	ft_reverse(t_design *design)
{
	design->angle[0] += 180;
	design->angle[1] += 180;
	design->angle[2] += 180;
}
