/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:24:16 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 18:08:19 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<ft_printf.h>

size_t	ft_nbr_size(t_lli nbr, t_lli len)
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

void	ft_putnbr_base(t_lli nbr, char *base, t_lli len, t_manager *stk)
{
	int		j;
	int		nbr_size;
	t_lli	aux;

	if (nbr < 0)
		nbr = -nbr;
	nbr_size = ft_nbr_size(nbr, len);
	while (nbr_size && !stk->info->err)
	{
		j = 0;
		aux = nbr;
		while (--nbr_size > 0)
		{
			j++;
			aux /= len;
		}
		ft_putnchar((base)[aux % len], 1, stk);
		nbr_size = j;
	}
}

void	ft_int_fl(t_lli n, t_manager *stk)
{
	int		esp;

	esp = (!n && !stk->flags->wdot && stk->flags->dot);
	stk->flags->plus *= n >= 0;
	stk->flags->space *= n >= 0;
	if (esp)
		stk->flags->width++;
	if (n < 0 || stk->flags->plus || stk->flags->space)
		stk->flags->width--;
	if (stk->flags->wdot < ft_nbr_size(n, 10))
		stk->flags->wdot = ft_nbr_size(n, 10);
	if (stk->flags->zero && !stk->flags->dot)
		stk->flags->wdot = stk->flags->width;
	ft_putnchar(' ', stk->flags->space, stk);
	ft_putnchar(' ', (stk->flags->width - stk->flags->wdot)
		* !stk->flags->dash, stk);
	ft_putnchar('-', (n < 0), stk);
	ft_putnchar('+', stk->flags->plus, stk);
	ft_putnchar('0', stk->flags->wdot - ft_nbr_size(n, 10), stk);
	if (!esp)
		ft_putnbr_base(n, B10, 10, stk);
	ft_putnchar(' ', (stk->flags->width - stk->flags->wdot)
		* stk->flags->dash, stk);
}

void	ft_hex_fl(unsigned int n, t_manager *stk, char fmt, char *hex)
{
	int		size;
	int		esp;

	esp = (!n && stk->flags->dot && !stk->flags->wdot);
	stk->flags->width += esp;
	if (!n)
		stk->flags->hastag = 0;
	if (stk->flags->wdot < ft_nbr_size(n, 16))
		stk->flags->wdot = ft_nbr_size(n, 16);
	size = stk->flags->width - stk->flags->wdot - (stk->flags->hastag * 2);
	ft_putnchar(' ', (size * !stk->flags->dash) * !stk->flags->zero, stk);
	ft_putnstr(hex, stk->flags->hastag * 2, stk);
	ft_putnchar('0', size * stk->flags->zero, stk);
	size = stk->flags->wdot - ft_nbr_size(n, 16);
	ft_putnchar('0', size, stk);
	if (fmt == 'x' && !esp)
		ft_putnbr_base(n, BL16, 16, stk);
	else if (fmt == 'X' && !esp)
		ft_putnbr_base(n, BU16, 16, stk);
	size = stk->flags->width - stk->flags->wdot - (stk->flags->hastag * 2);
	ft_putnchar(' ', (size * stk->flags->dash) * !stk->flags->zero, stk);
}
