/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:58:37 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/21 15:05:39 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int	fd1;
	int	fd2;
	char	buf;
	ssize_t	len;

	fd1 = open("example_file", O_RDWR|O_CREAT);
	fd2 = dup(fd1);
	write(fd2, "Hello world", strlen("Hello world"));
	printf("fd1 = %d, fd2 = %d\n", fd1, fd2);
	close(fd1);
	close(fd2);
	fd2 = open("example_file", O_RDONLY);
	len = read(fd2, &buf, 1);
	while (len)
	{
		printf("%c", buf);
		len = read(fd2, &buf, 1);
	}
	close(fd2);
}
