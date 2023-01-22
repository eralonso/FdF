/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_fl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:50:46 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/01 12:38:18 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

size_t	ft_size_ptr(t_ull ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		size = 1;
	while (ptr > 0)
	{
		size++;
		ptr /= 16;
	}
	return (size);
}

void	ft_ptr_fl(t_ull	ptr, t_manager *stack)
{
	int		j;
	int		size;
	t_ull	aux;

	ft_putnchar(' ', (stack->flags->width - (ft_size_ptr(ptr) + 2))
		* !stack->flags->dash, stack);
	ft_putnstr("0x", 2, stack);
	size = ft_size_ptr(ptr);
	aux = ptr;
	while (size && !stack->info->err)
	{
		j = 0;
		aux = ptr;
		while (--size > 0)
		{
			j++;
			aux /= 16;
		}
		ft_putnchar((BL16)[aux % 16], 1, stack);
		size = j;
	}
	ft_putnchar(' ', (stack->flags->width - (ft_size_ptr(ptr) + 2))
		* stack->flags->dash, stack);
}
