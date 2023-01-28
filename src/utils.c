#include	<fdf.h>

int	ft_error(char *str, char *file, int err)
{
	if (str)
		ft_printf(1, "%s", str);
	else if (err && file)
	{
		ft_printf(1, "FdF: %s: ", file);
		perror("");
	}
	else if (err)
		perror("");
	return (err);
}
