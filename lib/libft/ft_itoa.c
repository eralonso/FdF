/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:18:33 by eralonso          #+#    #+#             */
/*   Updated: 2022/09/29 13:28:55 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static long int	counter(long int num)
{
	long int	i;

	if (num < 0)
		num *= -1;
	i = 0;
	while (num > 9)
	{
		i++;
		num /= 10;
	}
	i++;
	return (i);
}

static char	*ft_create_str(long int num, char *str, long int size)
{
	long int	i;
	int			neg;

	neg = 0;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
		str[0] = '-';
	}
	i = -1;
	while (++i < (size - neg))
	{
		str[size - i - 1] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	long int	size;

	num = n;
	size = counter(num);
	if (n < 0)
		size++;
	str = (char *)ft_calloc(sizeof(char), (size + 1));
	if (!str)
		return (NULL);
	return (str = ft_create_str(num, str, size));
}
