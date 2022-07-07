
#include <unistd.h>

int	main(int ac, char **av)
{
	char	map[255];
	int		i;

	i = -1;
	if (ac == 3)
	{
		while (av[1][++i])
		{
			if (map[av[1][i]] != 1)
			{
				write(1, &av[1][i], 1);
				map[av[1][i]] = 1;
			}
		}
		i = -1;
		while (av[2][++i])
		{
			if (map[av[2][i]] != 1)
			{
				write(1, &av[2][i], 1);
				map[av[2][i]] = 1;
			}
		}
	}
	write(1, "\n", 1);
}