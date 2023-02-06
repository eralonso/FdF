/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/06 15:02:05 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	<ft_printf.h>
# include	<mlx.h>
# include	<math.h>
# include	<stdio.h>

//COLORS
# define WHITE (int)0x00FFFFFF

//KEY_CODES
# define KEY_ESC (int)53

//ERRORS
# define ERR_PARAM (char *)"Invalid number of arguments"
# define ERR_MAP (char *)"Map is incorrect"

//VIEWS
# define ISOMETRIC (int)30

typedef struct s_design	t_design;
typedef struct s_point	t_point;
typedef struct s_pixmap	t_pixmap;

struct s_point {
	float	x;
	float	y;
	float	z;
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
	float		width;
	float		height;
	t_point		*points;
	t_pixmap	pixmap;
	float		view;
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
void	ft_pixel_put(t_pixmap *pixmap, int x, int y, int color);
void	ft_print_line(t_point a, t_point b, t_design *design);
int		ft_clean_design(t_design *design, int num);

#endif
