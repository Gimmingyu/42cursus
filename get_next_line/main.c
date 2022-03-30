#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("test.txt", O_RDWR);
	result = get_next_line(fd);
	while (get_size_or_newline(result, 1) != -1)
	{
		printf("result = %s\n", result);
		result = get_next_line(fd);
		printf("result = %s\n", result);
	}
	free(result);
	return (0);
}
