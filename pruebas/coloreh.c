#include	<stdio.h>

int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= 0.5)
		rounded++;
	return (rounded);
}

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)(((endcolor >> 16)) - \
					((startcolor >> 16))) / (double)len;
	increment[1] = (double)(((endcolor >> 8)) - \
					((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) \
					/ (double)len;
	new[0] = (startcolor >> 16) + ft_round(pix * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(pix * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	//int	i = -1;
	//while (++i < 3)
	//	printf("increment[%i] == %f\n", i, increment[i]);
	//i = -1;
	//while (++i < 3)
	//	printf("new[%i] == %d\n", i, new[i]);
	printf("newcolor == %i\n\n", newcolor);
	return (newcolor);
}

int	main(void)
{
	int	color;
	int	start;
	int	end;
	int	len;
	int	pix;

	start = 0xFF0000;
	end = 0x00FF00;
	len = 10;
	pix = 10;
	printf("start == %i\n", start);
	printf("end == %i\n\n", end);
	//printf("r == %i\n", end >> 16);
	//printf("g == %i\n", (end >> 8) & 0xFF);
	//printf("b == %i\n", end & 0xFF);
	//                                                1 0 1 0 1 1 1 0 -> 0xAE == 174
	//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 -> 0xFF == 255
	//while (pix--)
		color = gradient(start, end, len, len);
	return (0);
}
