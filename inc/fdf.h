/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/09 18:32:34 by eralonso         ###   ########.fr       */
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
# define WHITE			(int)0x00FFFFFF
# define BLACK			(int)0x00000000
# define RED			(int)0x00FF0000
# define GREEN			(int)0x0000FF00
# define BLUE			(int)0x000000FF
# define LIGHT_BLUE		(int)0x0051D1F6
# define YELLOW			(int)0x00FFFF99
# define ORANGE			(int)0x00FFA500
# define L_GRAY			(int)0x00888888
# define GRAY			(int)0x00555555
# define CYAN			(int)0x0017E0E3
# define D_GRAY			(int)0x00222222
# define PINK			(int)0x00FF66FF
# define N_GRAY			(int)0x00F1F0E6
# define BROWN			(int)0x00562B05

///Menu
# define TXT_CLR		(int)0xEAEAEA
# define NBR_CLR		(int)0xF3AF3D

///Palette -> Neon
# define FUSCHIA		(int)0x00A239CA
# define VOID			(int)0x000E0B16
# define JEWEL			(int)0x004717F6

//Fin del mundo
// # define N_GREEN		(int)0x00000000
// # define N_ORANGE	(int)0x00B82601
// # define ORANGE		(int)0x00062F4F

// # define N_GREEN		(int)0x004CDEF5
// # define N_ORANGE	(int)0x00FC4A1A
// # define ORANGE		(int)0x00F19F4D

// # define N_GREEN		(int)0x0066B9BF

//Std
// # define ORANGE		(int)0x00FA910C
// # define N_ORANGE	(int)0x00FF0A35
// # define N_GREEN		(int)0x003CE5FB
// # define N_GREEN		(int)0x0000FFFF

//EVENT CODES
# define E_KEY_P 		(int)2
# define E_KEY_R 		(int)3
# define E_BTN_P 		(int)4
# define E_BTN_R 		(int)5
# define E_PTR_M 		(int)6
# define E_DESTROY_N	(int)17

//EVENTS MASKS
# define KEY_P_MASK 	(long)1
# define KEY_R_MASK 	(long)2
# define BTN_P_MASK 	(long)4
# define BTN_R_MASK 	(long)8
# define PTR_M_MASK 	(long)64
# define DESTROY_N_MASK	(long)131072

//KEY CODES
# define KEY_S				(int)1
# define KEY_D				(int)2
# define KEY_H				(int)4
# define KEY_G				(int)5
# define KEY_Z				(int)6
# define KEY_X				(int)7
# define KEY_C				(int)8
# define KEY_V				(int)9
# define KEY_B				(int)11
# define KEY_Q				(int)12
# define KEY_W				(int)13
# define KEY_R				(int)15
# define KEY_Y				(int)16
# define KEY_T				(int)17
# define KEY_1				(int)18
# define KEY_2				(int)19
# define KEY_3				(int)20
# define KEY_4				(int)21
# define KEY_5				(int)23
# define KEY_I				(int)34
# define KEY_P				(int)35
# define KEY_L				(int)37
# define KEY_ESC			(int)53
# define KEY_SUM			(int)69
# define KEY_RES			(int)78
# define KEY_CMD			(int)259
# define KEY_ARROW_LEFT		(int)123
# define KEY_ARROW_RIGHT	(int)124
# define KEY_ARROW_DOWN		(int)125
# define KEY_ARROW_UP		(int)126

//MOUSE CODES
# define BUTTON_LEFT	(int)1
# define BUTTON_RIGHT	(int)2
# define BUTTON_MIDDLE	(int)3
# define SCROLL_UP		(int)4
# define SCROLL_DOWN	(int)5

//ERRORS
# define ERR_PARAM	(char *)"Invalid number of arguments"
# define ERR_MAP	(char *)"Map is incorrect"

//WINDOW
# define WIN_WIDTH	(int)1920
# define WIN_HEIGHT	(int)1080

//MENU
# define MENU_WIDTH	(int)(WIN_WIDTH / 5)

typedef struct s_design		t_design;
typedef struct s_point		t_point;
typedef struct s_pixmap		t_pixmap;
typedef struct s_color		t_color;
typedef struct s_events		t_events;
typedef struct s_palette	t_palette;
typedef struct s_stat		t_stat;
typedef struct s_property	t_property;

struct s_point {
	float	x;
	float	y;
	float	z;
	float	r;
	float	fi;
	float	fita;
	int		color;
	float	select;
	char	hexa;
};

struct s_pixmap {
	void	*img;
	char	*addr;
	int		bpp;
	int		bytes_pp;
	int		line_len;
	int		endian;
};

struct	s_color {
	int		top;
	int		std;
	int		btm;
	int		bckg;
	int		menu;
};

struct	s_events {
	float		scale;
	int			show_menu;
	int			sphere;
	int			shadow;
	int			k_cmd;
	int			put_pt;
	t_point		btn_l;
	t_point		btn_r;
	t_point		sel_line;
	t_point		zoom;
	t_point		shift;
	t_point		sel_point;
};

struct	s_palette {
	t_color		def;
	t_color		wb;
	t_color		bw;
	t_color		real;
	t_color		neon;
};

struct	s_stat {
	int			width;
	int			height;
	int			max_z;
	int			min_z;
	int			size;
	int			inc_x;
	int			inc_y;
};

struct	s_property {
	float		z_div;
	int			density;
	float		angle[3];
	float		new_center[2];
	int			lines;
	int			dots;
};

struct s_design {
	t_stat		info;
	t_property	prop;
	t_events	event;
	t_color		color;
	t_palette	palette;
	t_point		*points;
	t_point		*copy;
	t_pixmap	pixmap;
	char		*map;
	float		render;
	void		*mlx;
	void		*mlx_win;
};

//Utils
int		ft_error(char *str, char *file, int err);
int		ft_clean_design(t_design *design, int num);
int		ft_close_program(void *param);
void	ft_config_points(t_point *copy, t_stat info, t_design *design);
int		ft_valid_point(t_point p);
t_point	*ft_copy_map(t_point *points, int size, int iterator);

//Config Points
void	ft_calculate_incs(t_design *design);
void	ft_rotate_x(t_point *points, float angle, int size[2], int iterator);
void	ft_rotate_y(t_point *points, float angle, int size[2], int iterator);
void	ft_rotate_z(t_point *points, float angle, int size[2], int iterator);
void	ft_scale(t_point *points, float axis[2], int size[2], int iterator);
void	ft_traslate(t_point *points, float axis[2], int size[2], int iterator);
void	ft_div_z(t_point *points, float div, int size[2], int iterator);

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
void	ft_print_menu(t_design *design);

//Print Utils
void	ft_pixel_put(t_pixmap *pixmap, int x, int y, int color);
void	ft_set_color(t_design *design, t_point *p, int min_z, int max_z);
void	ft_put_density(t_design *design, t_point c, int density);
int		ft_get_gradient(int start, int end, float len, float pos);
void	ft_pixel_put(t_pixmap *pixmap, int x, int y, int color);
void	ft_init_axis(t_point axis[4]);
void	ft_check_sphere(t_point *points, t_design *design, int size[2], \
		int iterator[2]);

//Polar
void	ft_polarize(t_design *design, t_point *points, int size);
void	ft_convert_rect(t_design *design, t_point *points, int size[2], \
		int iterator);

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
void	ft_restore_vars(t_design *design);

#endif
