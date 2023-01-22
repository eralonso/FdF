/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:56:37 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/07 09:12:35 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putnchar(char c, int n, t_manager *stk)
{
	int	aux;

	aux = 0;
	while (n-- > 0 && !stk->info->err)
	{
		aux = write(stk->info->fd, &c, 1);
		if (aux == -1)
		{
			stk->info->err = 1;
			return ;
		}
		stk->info->bytes += aux;
	}
}

void	ft_putnstr(char *str, int n, t_manager *stk)
{
	int	i;

	i = 0;
	while (str[i] && i < n && !stk->info->err)
		ft_putnchar(str[i++], 1, stk);
}

void	ft_char_fl(char c, t_manager *stk)
{
	ft_putnchar(' ', (stk->flags->width - 1) * !stk->flags->dash, stk);
	ft_putnchar(c, 1, stk);
	ft_putnchar(' ', (stk->flags->width - 1) * stk->flags->dash, stk);
}

void	ft_str_fl(char *str, t_manager *stack)
{
	if (!str)
		str = "(null)";
	if (stack->flags->wdot > ft_strlen(str) || !stack->flags->dot)
		stack->flags->wdot = ft_strlen(str);
	ft_putnchar(' ', (stack->flags->width - stack->flags->wdot)
		* !stack->flags->dash, stack);
	ft_putnstr(str, stack->flags->wdot, stack);
	ft_putnchar(' ', (stack->flags->width - stack->flags->wdot)
		* stack->flags->dash, stack);
}

void	ft_ofmt_fl(char fmt, t_manager *stack)
{
	char	c;

	c = ' ';
	if (stack->flags->zero)
		c = '0';
	ft_putnchar(c, (stack->flags->width - 1) * !stack->flags->dash, stack);
	ft_putnchar(fmt, 1, stack);
	ft_putnchar(c, (stack->flags->width - 1) * stack->flags->dash, stack);
}
