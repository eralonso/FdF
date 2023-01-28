/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:46:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/25 09:53:31 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_check_map(char *map)
{
	int	fd;
	//char	**r_map;

	if (ft_strrncmp(map, ".fdf\0", 4))
		return (ft_error(ERR_MAP, NULL, 0));
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit (ft_error(NULL, map, 1));
	//r_map = ft_read()
	//if (!ft_check_size(fd))
	//	return (ft_error(ERR_MAP, 0));
	return (1);
}
