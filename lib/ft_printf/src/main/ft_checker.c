/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:00:21 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/01 12:36:03 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_format_checker(t_manager *stack, char fmt)
{
	if (fmt == 'c')
		ft_char_fl(va_arg(stack->info->args, int), stack);
	else if (fmt == 's')
		ft_str_fl(va_arg(stack->info->args, char *), stack);
	else if (fmt == 'p')
		ft_ptr_fl(va_arg(stack->info->args, t_ull), stack);
	else if (fmt == 'd' || fmt == 'i')
		ft_int_fl(va_arg(stack->info->args, int), stack);
	else if (fmt == 'u')
		ft_int_fl(va_arg(stack->info->args, unsigned int), stack);
	else if (fmt == 'x')
		ft_hex_fl(va_arg(stack->info->args, unsigned int), stack, fmt, "0x");
	else if (fmt == 'X')
		ft_hex_fl(va_arg(stack->info->args, unsigned int), stack, fmt, "0X");
	else
		ft_ofmt_fl(fmt, stack);
}

void	ft_formatize(t_manager *stack, char *str)
{
	int	index;

	index = 0;
	if (*str == '%')
	{
		index = ft_flags_checker(stack->flags, ++str);
		if (str[index])
		{
			ft_format_checker(stack, str[index]);
			index++;
		}
	}
	else
	{
		ft_putnchar(*str, 1, stack);
		if (stack->info->err)
			return ;
	}
	stack->info->str = &stack->info->str[index + 1];
	stack->info->c = *stack->info->str;
}
