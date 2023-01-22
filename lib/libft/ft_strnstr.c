/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:08:41 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/03 15:26:23 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	start;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	j = 0;
	start = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] != needle[j])
		{
			i = ++start;
			j = 0;
		}
		if (haystack[i++] == needle[j])
		{
			if (!j++)
				start = i - 1;
			if (!needle[j])
				return ((char *)&haystack[start]);
		}
	}
	return (0);
}
