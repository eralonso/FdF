/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:37:27 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/13 13:33:59 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <fdf.h>

void	print_map_info(t_design *design, int *cords)
{
	ft_separator(cords, '\n', 0.5);
	put_str(design, cords, 1, "[<->MAP<->]");
	ft_separator(cords, '\n', 0.5);
	put_str(design, cords, 0, "Size :");
	put_nbr(design, cords, 1, design->info.size);
	put_str(design, cords, 0, "Max X:");
	put_nbr(design, cords, 1, design->info.width);
	put_str(design, cords, 0, "Max Y:");
	put_nbr(design, cords, 1, design->info.height);
	put_str(design, cords, 0, "Max Z:");
	put_nbr(design, cords, 1, design->info.max_z);
	put_str(design, cords, 0, "Min Z:");
	put_nbr(design, cords, 1, design->info.min_z);
	ft_separator(cords, '\n', 1);
}

void	print_draw_info(t_design *design, int *cords)
{
	float	axis[3];

	put_str(design, cords, 1, "[<-->DRAW<-->]");
	ft_separator(cords, '\n', 0.5);
	put_axis(design, cords, design->prop.angle, 1);
	put_str(design, cords, 1, "Point Selected");
	ft_separator(cords, '\t', 0.5);
	axis[0] = design->event.sel_point.x;
	axis[1] = design->event.sel_point.y;
	axis[2] = design->event.sel_point.z;
	put_axis(design, cords, axis, 0);
	put_str(design, cords, 0, "FPS: ");
	put_nbr(design, cords, 1, (int)(1000.0 / design->prop.render));
	put_str(design, cords, 0, "Scale:");
	put_nbr(design, cords, 1, design->event.scale);
	put_str(design, cords, 0, "Zoom:");
	put_float(design, cords, 1, design->event.zoom.z);
	put_str(design, cords, 0, "Div Z:");
	put_float(design, cords, 1, design->prop.z_div);
	put_str(design, cords, 0, "Size of Points:");
	if (design->prop.density)
		put_nbr(design, cords, 1, pow((design->prop.density * 2) - 1, 2));
	else
		put_nbr(design, cords, 1, 0);
	ft_separator(cords, '\n', 1);
}

void	print_palettes(t_design *design, int *cords)
{
	put_str(design, cords, 1, "[<--->PALETTE<--->] [ 1 - 5 ]");
	ft_separator(cords, '\n', 0.5);
	if (design->palette.def.id == design->color.id)
		print_palette(design, cords, "DEFAULT:", design->palette.def);
	else if (design->palette.real.id == design->color.id)
		print_palette(design, cords, "REAL:", design->palette.real);
	else if (design->palette.neon.id == design->color.id)
		print_palette(design, cords, "NEON:", design->palette.neon);
	else if (design->palette.bw.id == design->color.id)
		print_palette(design, cords, "BLACK & WHITE:", design->palette.bw);
	else if (design->palette.wb.id == design->color.id)
		print_palette(design, cords, "WHITE & BLACK:", design->palette.wb);
	ft_separator(cords, '\n', 1);
}

void	print_controls(t_design *design, int *cords)
{
	put_str(design, cords, 1, "[<---->CONTROLS<---->]");
	ft_separator(cords, '\n', 0.5);
	put_str(design, cords, 1, "Scroll: Zoom [ in / out ]");
	put_str(design, cords, 1, "Left Click: Rotate [ X / Y ] axis");
	put_str(design, cords, 1, "Right Click: Traslate Map [ X / Y ]");
	put_str(design, cords, 1, "+/-: Modify z divisor");
	put_str(design, cords, 1, "L/D: Show/Hidden [ Lines / Dots ]");
	put_str(design, cords, 1, "H: Show/Hidden Menu");
	put_str(design, cords, 1, "I/P/T: Isometric / Paralel / Top ");
	put_str(design, cords, 1, "G: Change to Polar [ Spherical ]");
	put_str(design, cords, 1, "V/B: Change size of points");
	put_str(design, cords, 1, "X/Y/Z: Rotate axis 180 degrees");
	put_str(design, cords, 1, "C: Center the Map");
	put_str(design, cords, 1, "CMD: Applies opacity to map");
	put_str(design, cords, 1, "CMD + Left Click: Select point");
	put_str(design, cords, 1, "S: Show/Hidden Shadow (Spherical)");
	put_str(design, cords, 1, "Arrows: Rotate [ X / Y ] axis");
	put_str(design, cords, 1, "Q/W: Rotate Z axis");
	put_str(design, cords, 1, "R: Restore Map");
	ft_separator(cords, '\n', 0.5);
	ft_separator(cords, '\t', 1);
	put_str(design, cords, 1, "Press [ \'esc\' ] to exit");
}

void	ft_print_menu(t_design *design)
{
	int	*cords;

	cords = ft_calloc(sizeof(int), 2);
	if (!cords)
		exit(ft_error(NULL, NULL, ft_clean_design(design, 1)));
	cords[0] = TAB;
	cords[1] = LINE_SPACING / 2;
	put_str(design, cords, 0, "{");
	put_str(design, cords, 0, design->map_name);
	put_str(design, cords, 1, "}");
	print_map_info(design, cords);
	print_draw_info(design, cords);
	print_palettes(design, cords);
	print_controls(design, cords);
	free(cords);
}
