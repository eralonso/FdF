/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:30:32 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/13 17:16:50 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <fdf_bonus.h>

void	ft_separator(int *cords, char s, float i)
{
	int	sep;
	int	half;
	int	iter;
	int	axi;

	half = 0;
	iter = i;
	if (i - iter == 0.5)
		half = 1;
	axi = 0;
	if (s == '\t')
		sep = TAB;
	else if (s == ' ')
		sep = CHAR_PX;
	else if (s == '\n')
	{
		sep = LINE_SPACING;
		axi = 1;
	}
	while (iter-- > 0)
		cords[axi] += sep;
	if (half == 1)
		cords[axi] += (int)((int)sep / 2);
}

void	put_str(t_design *design, int *cords, int iter, char *str)
{
	if (!str)
		str = "";
	mlx_string_put(design->mlx, design->mlx_win, cords[0], cords[1], \
					TXT_CLR, str);
	if (iter)
	{
		cords[0] = TAB;
		cords[1] += LINE_SPACING;
	}
	else
		cords[0] += (ft_strlen(str) * CHAR_PX) + CHAR_PX;
}

void	put_nbr(t_design *design, int *cords, int iter, int nbr)
{
	char	*num;

	num = ft_itoa(nbr);
	if (!num)
		exit(ft_error(NULL, NULL, ft_clean_design(design, 1)));
	mlx_string_put(design->mlx, design->mlx_win, cords[0], cords[1], \
					NBR_CLR, num);
	ft_free(&num, 2);
	if (iter)
	{
		cords[0] = TAB;
		cords[1] += LINE_SPACING;
	}
	else
		cords[0] += (ft_nbrlen_base(nbr, 10) * CHAR_PX) + \
					(CHAR_PX * (nbr < 0)) + CHAR_PX;
}

void	put_float(t_design *design, int *cords, int iter, float nbr)
{
	char		*num;
	static char	dec[3] = {'.', '0', '\0'};
	char		*tmp;

	num = ft_itoa(nbr);
	if (!num)
		exit(ft_error(NULL, NULL, ft_clean_design(design, 1)));
	dec[1] = ((int)(nbr * 10.0) - (((int)nbr) * 10)) + '0';
	tmp = num;
	num = ft_strjoin(num, dec);
	ft_free(&tmp, 2);
	if (!num)
		exit(ft_error(NULL, NULL, ft_clean_design(design, 1)));
	mlx_string_put(design->mlx, design->mlx_win, cords[0], cords[1], \
					NBR_CLR, num);
	ft_free(&num, 2);
	if (iter)
	{
		cords[0] = TAB;
		cords[1] += LINE_SPACING;
	}
	else
		cords[0] += ((ft_nbrlen_base(nbr, 10) + 2) * CHAR_PX) + \
					(CHAR_PX * (nbr < 0)) + CHAR_PX;
}

void	print_palette(t_design *design, int *cords, char *str, t_color plt)
{
	static int	size = 21;

	put_str(design, cords, 1, str);
	put_str(design, cords, 0, "(RGB)STD = [");
	put_nbr(design, cords, 0, (plt.std >> 16) & 0xFF);
	put_nbr(design, cords, 0, (plt.std >> 8) & 0xFF);
	put_nbr(design, cords, 0, plt.std & 0xFF);
	put_square(design, cords, size, plt.std);
	put_str(design, cords, 1, "]");
	put_str(design, cords, 0, "(RGB)BTM = [");
	put_nbr(design, cords, 0, (plt.btm >> 16) & 0xFF);
	put_nbr(design, cords, 0, (plt.btm >> 8) & 0xFF);
	put_nbr(design, cords, 0, plt.btm & 0xFF);
	put_square(design, cords, size, plt.btm);
	put_str(design, cords, 1, "]");
	put_str(design, cords, 0, "(RGB)TOP = [");
	put_nbr(design, cords, 0, (plt.top >> 16) & 0xFF);
	put_nbr(design, cords, 0, (plt.top >> 8) & 0xFF);
	put_nbr(design, cords, 0, plt.top & 0xFF);
	put_square(design, cords, size, plt.top);
	put_str(design, cords, 1, "]");
}
