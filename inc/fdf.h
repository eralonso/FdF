/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/28 19:03:34 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	<ft_printf.h>
# include	<mlx.h>
# include	<math.h>
# include	<float.h>
# include	<stdio.h>

//COLORS
# define WHITE		(int)0x00FFFFFF
# define RED		(int)0x00FF0000
# define GREEN		(int)0x0000FF00
# define BLUE		(int)0x000000FF
# define YELLOW		(int)0x00FFFF99
# define CYAN		(int)0x0017E0E3
# define GRAY		(int)0x00FAF6F5
# define D_GRAY		(int)0x00222222
# define ORANGE		(int)0x00FA910C
# define PINK		(int)0x00FF66FF
# define N_GRAY		(int)0x00F1F0E6
# define N_ORANGE	(int)0x00FF0A35
# define N_GREEN	(int)0x003CE5FB

//EVENT CODES
# define E_KEY_P (int)2
# define E_KEY_R (int)3
# define E_BTN_P (int)4
# define E_BTN_R (int)5
# define E_PTR_M (int)6
# define E_DESTROY_N (int)17

//EVENTS MASKS
# define KEY_P_MASK (long)1
# define KEY_R_MASK (long)2
# define BTN_P_MASK (long)4
# define BTN_R_MASK (long)8
# define PTR_M_MASK (long)64
# define DESTROY_N_MASK (long)131072

//KEY CODES
# define KEY_S (int)1
# define KEY_D (int)2
# define KEY_Z (int)6
# define KEY_X (int)7
# define KEY_Q (int)12
# define KEY_W (int)13
# define KEY_R (int)15
# define KEY_Y (int)16
# define KEY_W (int)13
# define KEY_T (int)17
# define KEY_SUM (int)30
# define KEY_I (int)34
# define KEY_P (int)35
# define KEY_RES (int)44
# define KEY_ESC (int)53
# define KEY_SUM2 (int)69
# define KEY_RES2 (int)78
# define KEY_CMD (int)259
# define KEY_ARROW_LEFT (int)123
# define KEY_ARROW_RIGHT (int)124
# define KEY_ARROW_DOWN (int)125
# define KEY_ARROW_UP (int)126

//MOUSE CODES
# define BUTTON_LEFT (int)1
# define BUTTON_RIGHT (int)2
# define BUTTON_MIDDLE (int)3
# define SCROLL_UP (int)4
# define SCROLL_DOWN (int)5

//ERRORS
# define ERR_PARAM (char *)"Invalid number of arguments"
# define ERR_MAP (char *)"Map is incorrect"

//WINDOW
# define WIN_WIDTH (int)1920
# define WIN_HEIGHT (int)1080

typedef struct s_design	t_design;
typedef struct s_point	t_point;
typedef struct s_pixmap	t_pixmap;
typedef struct s_color	t_color;

struct s_point {
	float	x;
	float	y;
	float	z;
	int		color;
	float	select;
	char	hexa;
};

struct s_pixmap {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct	s_color {
	int		top;
	int		std;
	int		btm;
	int		bckg;
};

struct s_design {
	int			width;
	int			height;
	int			max_z;
	int			min_z;
	int			size;
	int			density;
	float		angle[3];
	char		k_cmd;
	t_point		button_l;
	t_point		button_r;
	float		new_center[2];
	float		scale;
	t_point		sel_line;
	t_point		zoom;
	t_point		shift;
	t_color		color;
	t_point		*points;
	t_point		*copy;
	t_point		*current;
	t_pixmap	pixmap;
	char		*map;
	void		*mlx;
	void		*mlx_win;
};

//Utils
int		ft_error(char *str, char *file, int err);
int		ft_clean_design(t_design *design, int num);
int		ft_close_program(void *param);
void	ft_config_points(t_point *copy, t_design *design);
int		ft_valid_point(t_point p);
t_point	*ft_copy_map(t_point *points, int size);

//Config View
void	ft_rotate_x(t_point *points, float angle, int size);
void	ft_rotate_y(t_point *points, float angle, int size);
void	ft_rotate_z(t_point *points, float angle, int size);
void	ft_scale(t_point *points, float x, float y, int size);
void	ft_traslate(t_point *points, float x, float y, int size);

//View
void	ft_isometric(t_design *design);
void	ft_parallel(t_design *design);
void	ft_top(t_design *design);
void	ft_reverse(t_design *design);

//View Utils
int		ft_point_selected(t_design *design, t_point *p, int restart);

//Math Utils
float	ft_module(float x, float y);
int		ft_round(float n);

//Check Map
int		ft_check_map(char *map, t_design *design);
int		ft_read_all(int *fd, t_design *design);
int		ft_check_valid_map(int x, int y, t_design *design);
int		ft_check_valid_param(char **line, int i);
int		ft_check_hexa(char *str);

//Load Map
int		ft_load_map(t_design *design);
int		ft_load_points(t_design *design);
void	ft_fill_line_points(t_design *design, int y, char **cord);
void	ft_color(t_design *design);

//Print
int		ft_print_map(t_design *design);
void	ft_print_line(t_point a, t_point b, t_design *design, int density);
void	ft_print_axis(t_design *design);
void	ft_print_background(t_design *design);

//Print Utils
void	ft_pixel_put(t_pixmap *pixmap, int x, int y, int color);
void	ft_set_color(t_design *design, t_point *p, int min_z, int max_z);
void	ft_put_density(t_design *design, t_point c, int density);
int		ft_get_gradient(int start, int end, float len, float pos);

//Events
int		ft_key_press(int key_code, t_design *design);
int		ft_key_release(int key_code, t_design *design);
int		ft_btn_press(int button, int x, int y, t_design *design);
int		ft_btn_release(int button, int x, int y, t_design *design);
int		ft_mouse_move(int x, int y, t_design *design);

//Events Utils
void	ft_print_cord(int x, int y, t_design *design);
void	ft_redraw(t_design *design);
int		ft_change_view(int key_code, t_design *design);
int		ft_change_angle(int key_code, t_design *design);
int		ft_change_density(int key_code, t_design *design);

#endif
