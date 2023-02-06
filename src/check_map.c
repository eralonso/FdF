/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:46:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/02/06 19:59:05 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fdf.h>

int	ft_check_map(char *file, t_design *design)
{
	int	fd;
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (ft_strrncmp(file, ".fdf\0", 4))
		exit(ft_error(ERR_MAP, NULL, 0));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(ft_error(NULL, file, 1));
	if (!ft_check_read(&fd, &x, &y))
		exit (ft_error(ERR_MAP, NULL, 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(ft_error(NULL, file, 1));
	if (!ft_read_map(&fd, design, x, y))
		return (0);
	return (1);
}

int	ft_check_read(int *fd, int *x, int *y)
{
	char	*str;
	char	**line;

	str = get_next_line(*fd);
	while (str)
	{
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
		str = get_next_line(*fd);
		(*y)++;
	}
	if (ft_close(fd) == -1)
		return (ft_error(NULL, "close", 1));
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
