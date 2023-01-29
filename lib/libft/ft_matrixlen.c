/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:33:54 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 19:39:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_matrixlen(char **matrix)
{
	int	len;

	len = 0;
	if (!matrix)
		return (0);
	while (matrix[len])
		len++;
	return (len);
}
