/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:21:00 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/01 13:27:19 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>
#include	<stdio.h>

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	int		i;
	char	*base;

	i = 0;
	sign = 1;
	res = 0;
	base = B10;
	while (str[i] && ft_strchr("\n \t\v\r\f\0", str[i]))
		i++;
	if (ft_strnstr(str, "0X", 2) || ft_strnstr(str, "0x", 2))
	{
		base = BU16;
		i += 2;
	}
	else if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_strchr(base, ft_toupper(str[i])))
	{
		res = (ft_toupper(str[i]) - ('0' + (7 * ft_isalpha(str[i])))) + (res * ft_strlen(base));
		i++;
	}
	return (res * sign);
}
