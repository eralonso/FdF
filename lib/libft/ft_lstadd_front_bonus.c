/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:56:53 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 17:10:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
