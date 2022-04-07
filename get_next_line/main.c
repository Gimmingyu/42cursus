#include "get_next_line.h"

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*temp;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	temp = get_next_line(fd);
	while (*temp)
	{
		printf("%s\n", temp);
		temp = get_next_line(fd);
	}
	printf("%s\n", temp);
	free(temp);
	close(fd);
	return (0);
}
