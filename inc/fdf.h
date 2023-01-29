/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 19:53:58 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	<ft_printf.h>
# include	<mlx.h>
# include	<stdio.h>

# define BASE_HXL (char *)"0123456789abcdef"
# define BASE_HXU (char *)"0123456789ABCDEF"

# define ERR_PARAM (char *)"Invalid number of arguments"
# define ERR_MAP (char *)"Map is incorrect"

typedef	struct s_design t_design;

struct s_design {
	int		x;
	int		y;
	char	**map;
};

int		ft_error(char *str, char *file, int err);
int		ft_check_map(char *map, t_design *design);
int		ft_check_read(int *fd, int *x, int *y);
int		ft_check_valid_param(char **line);
int		ft_check_hexa(char *str);
int		ft_read_map(int *fd, t_design *design, int x, int y);

#endif
