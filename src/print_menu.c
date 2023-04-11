/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:37:27 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/11 19:50:34 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <fdf.h>

void	print_intro(t_design *design, int *cords)
{
	put_str(design, cords, 0, "//");
	put_str(design, cords, 0, design->map_name);
	put_str(design, cords, 1, "\\\\");
	ft_separator(cords, '\n', 0.5);
	put_str(design, cords, 1, "INFO");
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

void	print_info(t_design *design, int *cords)
{
	put_str(design, cords, 1, "Point Selected");
	printf("x: %f && y: %f && z: %f\n", design->event.sel_point.x, \
			design->event.sel_point.y, design->event.sel_point.z);
	put_str(design, cords, 0, "X:");
	if (design->event.put_pt && design->event.k_cmd)
		put_nbr(design, cords, 0, design->event.sel_point.x);
	put_str(design, cords, 0, "Y:");
	if (design->event.put_pt && design->event.k_cmd)
		put_nbr(design, cords, 0, design->event.sel_point.y);
	put_str(design, cords, 0, "Z:");
	if (design->event.put_pt && design->event.k_cmd)
		put_nbr(design, cords, 1, design->event.sel_point.z);
	else
		put_str(design, cords, 1, NULL);
	put_str(design, cords, 0, "R: ");
	put_nbr(design, cords, 0, design->render);
	put_str(design, cords, 1, "ms");
	put_str(design, cords, 0, "Scale:");
	put_nbr(design, cords, 1, design->event.scale);
	put_str(design, cords, 0, "Zoom:");
	put_float(design, cords, 1, design->event.zoom.z);
	put_str(design, cords, 0, "Div Z:");
	put_float(design, cords, 0, design->prop.z_div);
}

void	ft_print_menu(t_design *design)
{
	int	*cords;

	cords = ft_calloc(sizeof(int), 2);
	if (!cords)
		exit(ft_error(NULL, NULL, ft_clean_design(design, 1)));
	cords[0] = CHAR_PX;
	cords[1] = LINE_SPACING;
	print_intro(design, cords);
	print_info(design, cords);
	free(cords);
}
