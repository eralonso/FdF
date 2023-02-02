/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/02 19:05:54 by eralonso         ###   ########.fr       */
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
typedef struct s_pixmap	t_pixmap;

struct s_point {
	int		x;
	int		y;
	int		z;
	int		color;
};

struct s_pixmap {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
};

struct s_design {
	int			width;
	int			height;
	t_point		*points;
	t_pixmap	pixmap;
	void		*mlx;
	void		*mlx_win;
};

int		ft_error(char *str, char *file, int err);
int		ft_check_map(char *map, t_design *design);
int		ft_check_read(int *fd, int *x, int *y);
int		ft_check_valid_param(char **line);
int		ft_check_hexa(char *str);
int		ft_read_map(int *fd, t_design *design, int x, int y);
void	ft_create_line_points(t_design *design, int y, char **cord);
int		ft_print_map(t_design *design);
void	my_mlx_pixel_put(t_pixmap *pixmap, int x, int y, int color);

#endif
