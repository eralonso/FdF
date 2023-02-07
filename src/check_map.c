/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:46:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/07 16:37:08 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>
#define B_READ (int)500000

int	ft_check_map(char *file, t_design *design)
{
	int	fd;
	int	y;
	int	x;

	y = 0;
	x = 0;
	ft_printf(1, "  Checking map...\n");
	if (ft_strrncmp(file, ".fdf\0", 4))
		exit(ft_error("FdF: Extension incorrect", NULL, 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(ft_error(NULL, file, 1));
	if (!ft_check_read(&fd, &x, &y, design))
		exit (ft_error(ERR_MAP, NULL, 1));
	if (ft_close(&fd) == -1)
		exit (ft_error(ERR_MAP, "close", 1));
	//fd = open(file, O_RDONLY);
	//if (fd == -1)
	//	exit(ft_error(NULL, file, 1));
	if (!ft_load_map(design, x, y))
		return (0);
	//if (ft_close(fd) == -1)
	//	exit (ft_error(ERR_MAP, "close", 1));
	return (1);
}

int	ft_check_read(int *fd, int *x, int *y, t_design *design)
{
	char	*str;
	char	**line;
	int		bytes;

	str = get_next_line(*fd);
	//str = ft_calloc(sizeof(char), B_READ + 1);
	//if (!str)
	//	return (0);
	design->map = ft_strdup("");
	if (!design->map)
		return (0);
	bytes = 0;
	//bytes = read(*fd, str, B_READ);
	//while (bytes > 0)
	while (str)
	{
		bytes += ft_strlen(str);
		ft_printf(1, "\r    bytes read: [%i]\r", bytes);
		design->map = ft_strjoin(design->map, str);
		if (!design->map)
			return (0);
		line = ft_split(str, ' ');
		if (!line)
			return (ft_error(ft_free(&str, 2), NULL, 0));
		ft_free(&str, 2);
		if (!ft_check_valid_param(line))
			return (ft_free(line, 1) != NULL);
		if (*x == 0)
			*x = ft_matrixlen(line) - (1 * (*(line[ft_matrixlen(line) - 1]) == '\n'));
		else if (*x != ft_matrixlen(line) - (1 * (*(line[ft_matrixlen(line) - 1]) == '\n')))
			return (ft_free(line, 1) != NULL);
		ft_free(line, 1);
		//bytes += read(*fd, str, B_READ);
		str = get_next_line(*fd);
		(*y)++;
	}
	ft_printf(1, "\n");
	return (1);
}

int	ft_check_valid_param(char **line)
{
	int		i;
	char	**colon;
	char	*num;

	i = -1;
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
			if (ft_matrixlen(colon) > 2 || !ft_isnum(colon[0])
				|| !ft_isint(colon[0]) || !ft_check_hexa(colon[1]))
				return (ft_free(colon, 1) != NULL \
				|| ft_free(&num, 2) != NULL);
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
