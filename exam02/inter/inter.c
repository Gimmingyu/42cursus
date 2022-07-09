#include <unistd.h>

int	main(int ac, char **av)
{
	char	map[255];
	int		i;
	int		j;

	i = -1;
	if (ac == 3)
	{
		while (av[1][++i])
		{
			j = -1;
			while (av[2][++j])
			{
				if (map[av[1][i]] != 1 && (av[1][i] == av[2][j]))
				{
					write(1, &av[1][i], 1);
					map[av[1][i]] = 1;
				}
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
