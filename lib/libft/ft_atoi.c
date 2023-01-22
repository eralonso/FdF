/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:21:00 by eralonso          #+#    #+#             */
/*   Updated: 2022/09/24 12:41:07 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	s;
	int	i;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == 32 || \
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * s);
}
