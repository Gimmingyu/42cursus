#include "get_next_line.h"
#include <sys/fcntl.h>

int	main(void)
{
	int	fd;
	int	idx;

	idx = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	get_next_line(fd);
	return (0);
}
