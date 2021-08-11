#include "../includes/graphic.h"

void check_correct_argc(int argc, char **argv)
{
	if (argc != 2)
	{
		printf ("HOLA1\n");
		execut_error ();
	}
	if (ft_strlen(argv[1]) == 0)
	{
		printf ("HOLA2\n");
		execut_error (); 
	}
}

