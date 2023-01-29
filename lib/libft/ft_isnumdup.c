/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:05:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 14:11:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int	ft_isnumdup(char **input, int num, int index)
{
	int	i;

	i = -1;
	if (!input || !*input)
		return (0);
	while (++i < index)
	{
		if (num == ft_atoi(input[i]))
			return (1);
	}
	return (0);
}
