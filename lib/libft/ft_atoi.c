/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:21:00 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/31 18:41:51 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

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
	while (str[i] == '\n' || str[i] == '\t' || str[i] == 32 || \
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (ft_strnstr(str, "0X", 2) || ft_strnstr(str, "0x", 2))
		base = BU16;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_strchr(base, ft_toupper(str[i])))
		res = (str[i] - ('0' + (('A' - '0') * (ft_strchr(base, \
		ft_toupper(str[i])) != NULL)))) + (res * ft_strlen(base));
	return (res * sign);
}
