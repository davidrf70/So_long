#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	init_game(argv[1]);
	return (0);
}
