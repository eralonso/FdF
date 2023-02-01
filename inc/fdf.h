/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/01 19:32:59 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	<ft_printf.h>
# include	<mlx.h>
# include	<math.h>
# include	<stdio.h>

# define WHITE (int)0x00FFFFFF

# define ERR_PARAM (char *)"Invalid number of arguments"
# define ERR_MAP (char *)"Map is incorrect"

typedef struct s_design	t_design;
typedef struct s_point	t_point;

struct s_design {
	int		width;
	int		height;
	t_point	*points;
};

struct s_point {
	int		x;
	int		y;
	int		z;
	int		color;
};

int		ft_error(char *str, char *file, int err);
int		ft_check_map(char *map, t_design *design);
int		ft_check_read(int *fd, int *x, int *y);
int		ft_check_valid_param(char **line);
int		ft_check_hexa(char *str);
int		ft_read_map(int *fd, t_design *design, int x, int y);
void	ft_create_line_points(t_design *design, int y, char **cord);

#endif
