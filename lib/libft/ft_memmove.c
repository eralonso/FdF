/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:32:26 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 17:12:53 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len--)
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
