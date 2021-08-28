#include "graphic.h"

int	get_t(int trgb)
{
	return ((trgb & (0xFF << 24)) / pow(16, 6));
}

int	get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) / pow(16, 4));
}

int	get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) / pow(16, 2));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_trgb(int t, int r, int g, int b)
{
	int tot;

	tot = (t * pow(16, 6))  + (r * pow(16, 4)) + (g * pow(16, 2)) + b;
	return (tot);
}
