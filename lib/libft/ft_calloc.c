/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:44:53 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 17:07:30 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	ptr = (char *)malloc(size * count);
	if (!ptr)
		return (0);
	len = count * size;
	i = 0;
	while (i < len)
		ptr[i++] = 0;
	return (ptr);
}
