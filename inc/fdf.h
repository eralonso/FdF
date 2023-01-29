/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:05:05 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/29 14:33:29 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	<ft_printf.h>
# include	<mlx.h>
# include	<stdio.h>
# include	<fcntl.h>

# define BASE_HXL (char *)"0123456789abcdef"
# define BASE_HXU (char *)"0123456789ABCDEF"

# define ERR_PARAM (char *)"Invalid number of arguments"
# define ERR_MAP (char *)"Map is incorrect"

int		ft_error(char *str, char *file, int err);
int		ft_check_map(char *map);

#endif
