/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:46:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/04/13 17:15:19 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf_bonus.h>
#define B_READ (int)500000

int	ft_check_map(char *file, t_design *design)
{
	int	fd;

	if (ft_strrncmp(file, ".fdf\0", 4))
		exit(ft_error("👽 Extension incorrect", NULL, 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(ft_error(NULL, file, 1));
	design->map = ft_strdup("");
	if (!design->map)
		return (ft_close(&fd) * 0);
	ft_printf(1, "Reading map...\n");
	if (!ft_read_all(&fd, design))
		exit (ft_error(ERR_MAP, NULL, 1));
	if (ft_close(&fd) == -1)
		exit (ft_error(ERR_MAP, "close", 1));
	ft_printf(1, "Checking map...\n");
	if (!ft_check_valid_map(0, -1, design))
		exit(ft_free(&design->map, 2) == NULL);
	if (!ft_load_map(design))
		exit(ft_free(&design->map, 2) == NULL);
	design->map_name = file;
	if (ft_strrchr(file, '/'))
		design->map_name = ft_strrchr(file, '/') + 1;
	design->map_name[ft_strlen(design->map_name) - 4] = '\0';
	return (1);
}

int	ft_read_all(int *fd, t_design *design)
{
	char			*tmp;
	char			buffer[B_READ + 1];
	int				bytes;
	static int		print_bytes = 0;

	ft_bzero(buffer, B_READ);
	bytes = read(*fd, buffer, B_READ);
	while (bytes > 0)
	{
		print_bytes += bytes;
		ft_printf(1, "      \rbytes read: [%i]      \r", print_bytes);
		tmp = design->map;
		design->map = ft_strjoin(design->map, buffer);
		if (!design->map)
			return (ft_free(&tmp, 2) != 0);
		ft_free(&tmp, 2);
		ft_bzero(buffer, B_READ);
		bytes = read(*fd, buffer, B_READ);
	}
	if (bytes == -1)
		return (ft_error("🤯 Read error", ft_free(&tmp, 2), 1));
	ft_printf(1, "\n");
	return (1);
}

int	ft_check_valid_map(int x, int y, t_design *design)
{
	char		**cord;
	char		**line;

	cord = ft_split(design->map, '\n');
	if (!cord)
		return (0);
	while (cord[++y])
	{
		line = ft_split(cord[y], ' ');
		if (!line)
			return (ft_error("😭 Malloc error\n", ft_free(cord, 1), 0));
		if (x == 0)
			x = ft_matrixlen(line) - (*(line[ft_matrixlen(line) - 1]) == 10);
		if (!ft_check_valid_param(line, -1) || x != ft_matrixlen(line) - \
			(*(line[ft_matrixlen(line) - 1]) == 10))
			return (ft_error(ERR_COL, ft_free(line, 1), \
					ft_free(cord, 1) != NULL));
		ft_free(line, 1);
	}
	ft_free(cord, 1);
	design->info.width = x;
	design->info.height = y;
	design->info.size = x * y;
	return (1);
}

int	ft_check_valid_param(char **line, int i)
{
	char	**colon;
	char	*num;

	while (line[++i] && *(line[i]) != '\n')
	{
		num = ft_strtrim(line[i], "\n");
		if (!num)
			return (0);
		if (ft_strchr(num, ','))
		{
			colon = ft_split(num, ',');
			if (!colon)
				return (ft_free(&num, 2) != NULL);
			if (ft_matrixlen(colon) > 2 || !ft_isnum(colon[0]) \
			|| !ft_isint(colon[0]) || !ft_check_hexa(colon[1]))
				return (ft_free(colon, 1) != 0 || ft_free(&num, 2) != 0);
			ft_free(colon, 1);
		}
		else if (!ft_isnum(num) || !ft_isint(num))
			return (ft_free(&num, 2) != NULL);
		ft_free(&num, 2);
	}
	return (1);
}

int	ft_check_hexa(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (0);
	if (str[0] != '0' || !ft_strchr("xX\0", str[1]))
		return (0);
	while (str[++i])
		if (!ft_strchr(BU16, str[i]) && !ft_strchr(BL16, str[i]))
			return (0);
	if (i > 10)
		return (0);
	return (1);
}
