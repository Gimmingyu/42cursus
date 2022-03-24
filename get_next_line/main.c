#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	idx;

	idx = 0;
	fd = 0;
	while (argv[idx] && idx < argc)
		printf("argv[idx] = %s\n", argv[idx++]);
	get_next_line(0);
	return (0);
}
