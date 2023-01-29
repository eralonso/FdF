/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:52:19 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 17:15:14 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)&s[0];
	while (*s)
		s++;
	while ((char *)s != (str - 1))
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
