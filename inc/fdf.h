/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/10 12:12:44 by eralonso         ###   ########.fr       */
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
	char	hexa;
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
	int			max_z;
	int			size;
	t_point		*points;
	t_pixmap	pixmap;
	char		*map;
	float		view;
	void		*mlx;
	void		*mlx_win;
};

//Utils
int		ft_error(char *str, char *file, int err);
int		ft_clean_design(t_design *design, int num);
int		ft_close_program(void *param);
void	ft_config_point(t_point *p, t_design *design, float width, float height);

//Check Map
int		ft_check_map(char *map, t_design *design);
int		ft_read_all(int *fd, t_design *design);
int		ft_check_valid_map(int x, int y, t_design *design);
int		ft_check_valid_param(char **line, int i);
int		ft_check_hexa(char *str);

//Load Map
int		ft_load_map(t_design *design);
void	ft_fill_line_points(t_design *design, int y, char **cord);

//Print
int		ft_print_map(t_design *design);
void	ft_pixel_put(t_pixmap *pixmap, int x, int y, int color);
void	ft_print_line(t_point a, t_point b, t_design *design);

//Events
int		ft_events(int key_code, void *design);

#endif
