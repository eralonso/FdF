#include	<stdio.h>
#include	<limits.h>
#include	<float.h>

int	main(void)
{
	double	d;
	float	f;

	d = DBL_MAX;
	f = FLT_MAX;
	printf("MAX:\ndouble == %f\n", d);
	printf("float == %f\n", f);
	d *= -1;
	f *= -1;
	d -= 0.234565432;
	f -= 0.2345432;
	printf("\nMIN:\ndouble == %f\n", d);
	printf("float == %f\n", f);
	return (0);
}
