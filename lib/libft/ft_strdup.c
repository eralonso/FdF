/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:16:49 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 17:15:23 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dup)
		return (0);
	i = -1;
	while (++i < ft_strlen(str))
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
