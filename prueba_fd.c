#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"lib/libft/libft.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*str;

	if (ac < 2)
	{
		printf("Too few arguments\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
