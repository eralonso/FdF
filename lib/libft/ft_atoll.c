/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:06:27 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 14:39:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

long long	ft_atoll(char *str)
{
	long long	neg;
	long long	res;

	neg = 1;
	res = 0;
	if (!str || !*str)
		return (0);
	while (*str && ft_strchr("\t \n\t\r\v\f", *str))
		str++;
	if (*str && *str == '-')
		neg = -1;
	if (*str && ft_strchr("+-", *str))
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	return (res * neg);
}
