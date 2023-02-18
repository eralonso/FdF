/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:30 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	<ft_printf.h>
# include	<mlx.h>
# include	<math.h>
# include	<stdio.h>

//COLORS
# define WHITE	(int)0x00FFFFFF
# define RED	(int)0x00FF0000
# define GREEN	(int)0x0000FF00
# define BLUE	(int)0x000000FF

//EVENT CODES
# define E_KEY_P (int)2
# define E_KEY_R (int)3
# define E_BUTTON_P (int)4
# define E_BUTTON_R (int)5
# define E_POINTER_M (int)6
# define E_DESTROY_N (int)17

//EVENTS MASKS
# define KEY_P_MASK (long)1L << 0
# define KEY_R_MASK (long)1L << 1
# define BUTTON_P_MASK (long)1L << 2
# define BUTTON_R_MASK (long)1L << 3
# define POINTER_M_MASK (long)1L << 6
# define DESTROY_N_MASK (long)1L << 17

//KEY CODES
# define KEY_R (int)15
# define KEY_I (int)34
# define KEY_P (int)35
# define KEY_ESC (int)53
# define KEY_ARROW_LEFT (int)123
# define KEY_ARROW_RIGHT (int)124
# define KEY_ARROW_DOWN (int)125
# define KEY_ARROW_UP (int)126

//ERRORS
# define ERR_PARAM (char *)"Invalid number of arguments"
# define ERR_MAP (char *)"Map is incorrect"

//WINDOW
# define WIN_WIDTH (int)1920
# define WIN_HEIGHT (int)1080

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
	int		line_len;
	int		endian;
};

struct s_design {
	int			width;
	int			height;
	int			max_z;
	int			min_z;
	int			size;
	t_point		*points;
	t_point		*copy;
	t_pixmap	pixmap;
	float		angle[3];
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
int		ft_valid_point(t_point p);

//Config view
void	ft_rotate_x(t_point *p, float angle);
void	ft_rotate_y(t_point *p, float angle);
void	ft_rotate_z(t_point *p, float angle);

//View
void	ft_isometric(t_design *design);
void	ft_parallel(t_design *design);
void	ft_neutral(t_design *design);

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
int		ft_key_press(int key_code, t_design *design);
int		ft_key_release(int key_code, t_design *design);
int		ft_button_press(int button, int x, int y, t_design *design);
int		ft_button_release(int button, int x, int y, t_design *design);
int		ft_mouse_move(int x, int y, t_design *design);

#endif
