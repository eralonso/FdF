/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:35:12 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/05 10:07:06 by eralonso         ###   ########.fr       */
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
		perror("Error: ");
	return (err);
}

int	ft_valid_point(t_point p)
{
	if (p.x < 0 || p.x >= WIN_WIDTH || p.y < 0 || p.y >= WIN_HEIGHT)
		return (0);
	return (1);
}

int	ft_clean_design(t_design *design, int num)
{
	ft_free((char **)&(design->points), 2);
	ft_free(&design->map, 2);
	ft_free((char **)&(design->copy), 2);
	return (num);
}

int	ft_close_program(void *param)
{
	t_design	*design;

	design = (t_design *)param;
	mlx_destroy_image(design->mlx, design->pixmap.img);
	mlx_destroy_window(design->mlx, design->mlx_win);
	ft_clean_design(design, 0);
	exit(0);
	return (1);
}

t_point	*ft_copy_map(t_point *points, int size, int iterator)
{
	t_point	*copy;
	int		i;

	copy = ft_calloc(sizeof(t_point), size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = points[i];
		i += iterator;
	}
	return (copy);
}
