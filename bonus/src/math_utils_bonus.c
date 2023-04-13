/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:50:13 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/13 17:16:44 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf_bonus.h>

float	ft_module(float x, float y)
{
	float	mod;

	mod = sqrt((x * x) + (y * y));
	return (mod);
}

int	ft_round(float n)
{
	int	rounded;

	rounded = n;
	if (n - rounded >= 0.5)
		rounded++;
	return (rounded);
}
