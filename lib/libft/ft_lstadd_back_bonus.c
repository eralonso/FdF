/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:07:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 17:10:19 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		ptr = ft_lstlast(*lst);
		ptr->next = new;
	}
}
