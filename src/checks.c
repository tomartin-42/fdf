#include "../includes/graphic.h"

void check_correct_argc(int argc, char **argv)
{
	if (argc != 1)
		execut_error ();
	if (ft_strlen(argv[argc]) == 0)
		execut_error (); 
}

