/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:10:39 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/05 10:05:36 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

void	ft_isometric(t_design *design)
{
	design->prop.angle[0] = 45;
	design->prop.angle[1] = 0;
	design->prop.angle[2] = 45;
}

void	ft_parallel(t_design *design)
{
	design->prop.angle[0] = 90;
	design->prop.angle[1] = 0;
	design->prop.angle[2] = 0;
}

void	ft_top(t_design *design)
{
	design->prop.angle[0] = 0;
	design->prop.angle[1] = 0;
	design->prop.angle[2] = 0;
}

void	ft_reverse(t_design *design)
{
	design->prop.angle[0] += 180;
	design->prop.angle[1] += 180;
	design->prop.angle[2] += 180;
}
