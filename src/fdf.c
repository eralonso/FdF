/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:04:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/24 12:43:19 by eralonso         ###   ########.fr       */
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

static void	ft_init_design(t_design *design)
{
	ft_top(design);
	design->color.top = N_ORANGE;
	design->color.std = ORANGE;
	design->color.btm = N_GREEN;
	design->color.bckg = D_GRAY;
	design->zoom.z = 1;
	design->zoom.x = 0;
	design->zoom.y = 0;
	design->shift.x = 0;
	design->shift.y = 0;
	design->button_l.z = 0;
	design->button_r.z = 0;
	design->k_cmd = 0;
	design->sel_line.z = 0;
}

static void	ft_init_mlx(t_design *design)
{
	design->mlx = mlx_init();
	design->mlx_win = mlx_new_window(design->mlx, WIN_WIDTH, \
	WIN_HEIGHT, "FdF eralonso");
	design->pixmap.img = mlx_new_image(design->mlx, WIN_WIDTH, WIN_HEIGHT);
	design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, \
	&design->pixmap.bpp, &design->pixmap.line_len, &design->pixmap.endian);
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
