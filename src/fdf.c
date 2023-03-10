/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:04:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/03/12 13:26:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

	//design->color.top = RED;
	//design->color.std = WHITE;
	//design->color.btm = BLUE;
	//design->color.top = ORANGE;
	//design->color.std = GRAY;
	//design->color.btm = CYAN;
	//design->color.top = ORANGE;
	//design->color.std = GRAY;
	//design->color.btm = CYAN;

static void	ft_init_colors(t_design *design)
{
	design->palette.def.top = N_ORANGE;
	design->palette.def.std = ORANGE;
	design->palette.def.btm = N_GREEN;
	design->palette.def.bckg = D_GRAY;
	design->palette.wb.top = WHITE;
	design->palette.wb.std = WHITE;
	design->palette.wb.btm = WHITE;
	design->palette.wb.bckg = BLACK;
	design->palette.bw.top = BLACK;
	design->palette.bw.std = BLACK;
	design->palette.bw.btm = BLACK;
	design->palette.bw.bckg = WHITE;
	design->palette.real.top = RED;
	design->palette.real.std = GREEN;
	design->palette.real.btm = BLUE;
	design->palette.real.bckg = D_GRAY;
}

static void	ft_init_design(t_design *design)
{
	ft_top(design);
	ft_init_colors(design);
	design->color = design->palette.def;
	design->event.zoom.z = 1;
	design->event.zoom.x = 0;
	design->event.zoom.y = 0;
	design->event.shift.x = 0;
	design->event.shift.y = 0;
	design->event.button_l.z = 0;
	design->event.button_r.z = 0;
	design->event.k_cmd = 0;
	design->event.sel_line.z = 0;
	design->density = 1;
	design->new_center[0] = WIN_WIDTH / 2;
	design->new_center[1] = WIN_HEIGHT / 2;
	design->copy = NULL;
	design->current = NULL;
	design->dots = 0;
	design->lines = 1;
	design->z_div = 32;
	design->event.sphere = 0;
	design->event.shadow = 0;
}

static void	ft_init_mlx(t_design *design)
{
	design->mlx = mlx_init();
	design->mlx_win = mlx_new_window(design->mlx, WIN_WIDTH, \
	WIN_HEIGHT, "FdF eralonso");
	design->pixmap.img = mlx_new_image(design->mlx, WIN_WIDTH, WIN_HEIGHT);
	design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, \
	&design->pixmap.bpp, &design->pixmap.line_len, &design->pixmap.endian);
	design->pixmap.bytes_pp = design->pixmap.bpp / 8;
}

int	main(int ac, char **av)
{
	t_design	design;

	if (ac != 2)
		return (1);
	ft_init_design(&design);
	if (!ft_check_map(av[1], &design))
		return (ft_error("Error found checking de map\n", NULL, 1));
	ft_init_mlx(&design);
	if (!ft_print_map(&design))
		return (ft_error("Error found drawing de map\n", NULL, 1));
	mlx_hook(design.mlx_win, E_KEY_P, KEY_P_MASK, ft_key_press, &design);
	mlx_hook(design.mlx_win, E_KEY_R, KEY_R_MASK, ft_key_release, &design);
	mlx_hook(design.mlx_win, E_BTN_P, BTN_P_MASK, ft_btn_press, &design);
	mlx_hook(design.mlx_win, E_BTN_R, BTN_R_MASK, ft_btn_release, &design);
	mlx_hook(design.mlx_win, E_PTR_M, PTR_M_MASK, ft_mouse_move, &design);
	mlx_hook(design.mlx_win, E_DESTROY_N, DESTROY_N_MASK, \
	ft_close_program, &design);
	mlx_loop(design.mlx);
	ft_clean_design(&design, 0);
	return (0);
}
