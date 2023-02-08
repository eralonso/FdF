/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:29:55 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/08 16:22:59 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	s3 = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
	return (s3);
}
