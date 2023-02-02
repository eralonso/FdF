/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:35:12 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/02 18:05:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<fdf.h>

int	ft_error(char *str, char *file, int err)
{
	if (str)
		ft_printf(1, "%s\n", str);
	else if (err && file)
	{
		ft_printf(1, "FdF: %s: ", file);
		perror("");
	}
	else if (err)
		perror("");
	return (err);
}

void	my_mlx_pixel_put(t_pixmap *pixmap, int x, int y, int color)
{
	char	*dst;

	dst = pixmap->addr + (y * pixmap->line_length + x * (pixmap->bpp / 8));
	*(unsigned int *)dst = color;
}
