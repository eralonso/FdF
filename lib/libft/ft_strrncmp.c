/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:03:27 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/25 09:50:44 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	int	s1_len;
	int	s2_len;

	if (!n || !s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1_len || !s2_len)
		return (*s1 - *s2);
	while (s1[s1_len - 1] && s2[s2_len - 1] && --n)
	{
		if (s1[s1_len - 1] != s2[s2_len - 1])
			return (s1[s1_len - 1] - s2[s2_len - 1]);
		s1_len--;
		s2_len--;
	}
	return (s1[s1_len - 1] - s2[s2_len - 1]);
}
