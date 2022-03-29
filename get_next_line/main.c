#include "get_next_line.h"

int	main(void)
{
	char	ptr[10];
	int		fd;
	size_t	length;

	fd = open("test.txt", O_WRONLY);
	length = read(fd, ptr, 10);
	size_t	idx = 0;
	while (idx < length)
		printf("%c", ptr[idx++]);
	length = read(fd, ptr, 10);
	idx = 0;
	printf("\n");
	while (idx < length)
		printf("%c", ptr[idx++]);
	return (0);
}
