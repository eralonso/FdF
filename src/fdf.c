/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:04:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/19 12:14:39 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_init_mlx_design(t_design *design)
{
	design->mlx = NULL;
	design->mlx_win = NULL;
	design->pixmap.img = NULL;
	design->mlx = mlx_init();
	if (!design->mlx)
		return (0);
	design->mlx_win = mlx_new_window(design->mlx, WIN_WIDTH, \
	WIN_HEIGHT, "FdF eralonso");
	if (!design->mlx_win)
		return (ft_clean_design(design, 0));
	design->pixmap.img = mlx_new_image(design->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!design->pixmap.img)
		return (ft_clean_design(design, 0));
	design->pixmap.addr = mlx_get_data_addr(design->pixmap.img, \
	&design->pixmap.bpp, &design->pixmap.line_len, &design->pixmap.endian);
	ft_neutral(design);
	design->zoom = 1;
	design->shift.x = 0;
	design->shift.y = 0;
	design->button_l.z = 0;
	design->button_r.z = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_design	design;

	if (ac != 2)
		return (1);
	if (!ft_check_map(av[1], &design))
		return (ft_error(NULL, NULL, 1));
	if (!ft_init_mlx_design(&design))
		return (1);
	if (!ft_print_map(&design))
		return (ft_error(NULL, NULL, 1));
	mlx_hook(design.mlx_win, E_KEY_P, KEY_P_MASK, ft_key_press, &design);
	mlx_hook(design.mlx_win, E_KEY_R, KEY_R_MASK, ft_key_release, &design);
	mlx_hook(design.mlx_win, E_BUTTON_P, BUTTON_P_MASK, ft_button_press, &design);
	mlx_hook(design.mlx_win, E_BUTTON_R, BUTTON_R_MASK, \
	ft_button_release, &design);
	mlx_hook(design.mlx_win, E_POINTER_M, POINTER_M_MASK, ft_mouse_move, &design);
	mlx_hook(design.mlx_win, E_DESTROY_N, DESTROY_N_MASK, \
	ft_close_program, &design);
	mlx_loop(design.mlx);
	ft_clean_design(&design, 0);
	return (0);
}
