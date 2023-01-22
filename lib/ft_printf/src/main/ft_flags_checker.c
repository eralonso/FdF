/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:57:07 by eralonso          #+#    #+#             */
/*   Updated: 2022/12/01 12:36:26 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_flag_selector(t_flags *flags, char fmt)
{
	fmt = ft_tolower(fmt);
	flags->hastag *= (fmt == 'x');
	flags->space *= ((fmt == 'd' || fmt == 'i') && !flags->plus);
	flags->plus *= (fmt == 'd' || fmt == 'i');
	flags->zero *= (fmt != 'c' && fmt != 'p' && fmt != 's'
			&& !flags->dash && (!(flags->width && flags->dot && (fmt != 'c'
						|| fmt != 's' || fmt != 'p'))));
	flags->dot *= (ft_strchr((FT), fmt) && fmt != 'c' && fmt != 'p');
	flags->wdot *= flags->dot;
}

int	ft_min_width(t_flags *flags, char *str)
{
	int	index;

	flags->width = 0;
	index = 0;
	while (str[index] && ft_isdigit(str[index]))
	{
		flags->width = (str[index] - '0') + (flags->width * 10);
		index++;
	}
	return (index - 1);
}

int	ft_accuracy(t_flags *flags, char *str)
{
	int	index;

	index = 0;
	flags->dot = 1;
	flags->wdot = 0;
	while (str[index] && ft_isdigit(str[index]))
	{
		flags->wdot = (str[index] - '0') + (flags->wdot * 10);
		index++;
	}
	return (index);
}

int	ft_flags_checker(t_flags *flags, char *str)
{
	int		index;

	index = -1;
	while (str[++index] && ft_strchr((FL), str[index]))
	{
		if (str[index] == '.')
			index += ft_accuracy(flags, &str[index + 1]);
		else if (str[index] == '#')
			flags->hastag = 1;
		else if (str[index] == ' ')
			flags->space = 1;
		else if (str[index] == '-')
			flags->dash = 1;
		else if (str[index] == '0')
			flags->zero = 1;
		else if (ft_isdigit(str[index]))
			index += ft_min_width(flags, &str[index]);
		else if (str[index] == '+')
			flags->plus = 1;
	}
	if (index > 0)
		ft_flag_selector(flags, str[index]);
	return (index);
}
