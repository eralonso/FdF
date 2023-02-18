/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:10:39 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:24 by eralonso         ###   ########.fr       */
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

void	ft_neutral(t_design *design)
{
	design->angle[0] = 0;
	design->angle[1] = 0;
	design->angle[2] = 0;
}
