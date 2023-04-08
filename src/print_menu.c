/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:37:27 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/08 19:24:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <fdf.h>

#define TAB             (int)30
#define CHAR_PX         (int)10
#define LINE_SPACING    (int)30

void    put_nbr(t_design *design, int *cords, int iter, int nbr)
{
    char    *num;

    num = ft_itoa(nbr);
    if (!num)
        exit(ft_error(NULL, NULL, ft_clean_design(design, 1)));
    mlx_string_put(design->mlx, design->mlx_win, cords[0], cords[1], NBR_CLR, num);
    ft_free(&num, 2);
    if (iter)
    {
        cords[0] = TAB;
        cords[1] += LINE_SPACING;
    }
    else
        cords[0] += (ft_nbrlen_base(nbr, 10) * CHAR_PX) + CHAR_PX;
}

void    put_str(t_design *design, int *cords, int iter, char *str)
{
    mlx_string_put(design->mlx, design->mlx_win, cords[0], cords[1], TXT_CLR, str);
    if (iter)
    {
        cords[0] = TAB;
        cords[1] += LINE_SPACING;
    }
    else
        cords[0] += (ft_strlen(str) * CHAR_PX) + CHAR_PX;
}

void    print_intro(t_design *design, int *cords)
{
    put_str(design, cords, 0, "HELLO");
    put_str(design, cords, 0, "WORLD");
    put_str(design, cords, 0, "I'M");
    put_str(design, cords, 1, "ERIC");
    put_str(design, cords, 1, "HELLO WORLD I'M ERIC");
    put_str(design, cords, 0, "HELLO");
    put_nbr(design, cords, 1, 42);
    put_str(design, cords, 1, "HELLO BARCELONA");
}

void    ft_print_menu(t_design *design)
{
    int *cords;

    cords = ft_calloc(sizeof(int), 2);
    if (!cords)
        exit(ft_error(NULL, NULL, ft_clean_design(design, 1)));
    cords[0] = TAB;
    cords[1] = LINE_SPACING;
    print_intro(design, cords);
    free(cords);
}