/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:50:13 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/27 16:12:12 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

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
