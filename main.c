#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>

float	ft_sqrt(float number)
{
	long		i;
	float		x2, y;
	const float	threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = * ( long * ) &y;
	i = 0x5f3759df - ( i >> 1 );
	y = * ( float * ) &i;
	y = y * ( threehalfs - ( x2 * y * y ) );
	//y = y * ( threehalfs - ( x2 * y * y ) );
	return (y);
}

int	main(int ac, char **av)
{
	float	num;
	float	res1;
	float	res2;

	if (ac < 2)
		return (1);
	num = atof(av[1]);
	printf("El numero es: %f\n", num);
	res1 = ft_sqrt(num);
	res2 = sqrt(num);
	printf("ft_sqrt: La raiz cuadrada de %s es: %f\n", av[1], res1);
	printf("sqrt: La raiz cuadrada de %s es: %f\n", av[1], res2);
}
/*
0 0 0 0 0 0 1 0 // 2
0 0 0 0 0 0 1 0 // 2
0 0 0 0 0 1 0 0 // 4

0 0 0 0 0 0 1 1 // 3
0 0 0 0 0 0 1 1 // 3
0 0 0 0 1 0 0 1 // 9

0 0 0 0 0 1 0 0 // 4
0 0 0 0 0 1 0 0 // 4
0 0 0 1 0 0 0 0 // 16

0 0 0 0 0 1 0 1 // 5
0 0 0 0 0 1 0 1 // 5
0 0 0 1 1 0 0 1 // 25

0 0 0 0 0 1 1 0 // 6
0 0 0 0 0 1 1 0 // 6
0 0 1 0 0 1 0 0 // 36

0 0 0 0 0 1 1 1 // 7
0 0 0 0 0 1 1 1 // 7
0 0 1 1 0 0 0 1 // 49

0 0 0 0 1 0 0 0 // 8
0 0 0 0 1 0 0 0 // 8
0 1 0 0 0 0 0 0 // 64

0 0 0 0 1 0 0 1 // 9
0 0 0 0 1 0 0 1 // 9
0 1 0 1 0 0 0 1 // 81

0 0 0 0 1 0 1 0 // 10
0 0 0 0 1 0 1 0 // 10
0 1 1 0 0 1 0 0 // 100

0 0 0 0 1 0 1 1 // 11
0 0 0 0 1 0 1 1 // 11
0 1 1 1 1 0 0 1 // 121

0 0 0 0 1 1 0 0 // 12
0 0 0 0 1 1 0 0 // 12
1 0 0 1 0 0 0 0 // 144

0 0 0 0 1 1 0 1 // 13
0 0 0 0 1 1 0 1 // 13
1 0 1 0 1 0 0 1 // 169

0 0 0 0 1 1 1 0 // 14
0 0 0 0 1 1 1 0 // 14
1 1 0 0 0 1 0 0 // 196
*/
