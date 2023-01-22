/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:36:00 by eralonso          #+#    #+#             */
/*   Updated: 2022/09/21 13:47:37 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (*lst)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = ptr;
		}
		*lst = 0;
	}
}
