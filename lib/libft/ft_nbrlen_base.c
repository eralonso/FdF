/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:09:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 18:34:57 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

size_t	ft_nbrlen_base(long long nbr, long long len)
{
	int	nbr_size;

	nbr_size = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr_size++;
		nbr /= len;
	}
	return (nbr_size);
}
