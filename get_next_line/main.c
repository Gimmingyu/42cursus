/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:14:03 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/10 19:16:58 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

ssize_t	fnew(char *temp)
{
	ssize_t	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	main(void)
{
	char	*temp;
	int		fd1;
	// int		fd2;
	// int		fd3;
	fd1 = open("multiple_line_no_nl", O_RDWR);
	temp = get_next_line(fd1);
	printf("temp is %s\n", temp);
	printf("new line is in temp[%zd]\n", fnew(temp));
	free(temp);
	temp = get_next_line(fd1);
	printf("temp is %s\n", temp);
	printf("new line is in temp[%zd]\n", fnew(temp));
	free(temp);
	temp = get_next_line(fd1);
	printf("temp is %s\n", temp);
	printf("new line is in temp[%zd]\n", fnew(temp));
	free(temp);
	temp = get_next_line(fd1);
	printf("temp is %s\n", temp);
	printf("new line is in temp[%zd]\n", fnew(temp));
	free(temp);
	temp = get_next_line(fd1);
	printf("temp is %s\n", temp);
	printf("new line is in temp[%zd]\n", fnew(temp));
	free(temp);
	// temp = get_next_line(fd1);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// printf("gnl success\n");
	// fd2 = open("no_word.txt", O_RDWR);
	// temp = get_next_line(fd2);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// // free(temp);
	// temp = get_next_line(fd2);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// // free(temp);
	// temp = get_next_line(fd2);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// // free(temp);
	// printf("gnl success\n");
	// fd3 = open("test2.txt", O_RDWR);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// temp = get_next_line(fd3);
	// printf("temp is %s\n", temp);
	// printf("new line is in temp[%zd]\n", fnew(temp));
	// free(temp);
	// printf("gnl success\n");
	close(fd1);
	// close(fd2);
	// close(fd3);
	// free(temp);
	return (0);
}
