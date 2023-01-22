/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:10:36 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/07 17:47:15 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
