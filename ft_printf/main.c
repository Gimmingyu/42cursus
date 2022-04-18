/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:40:02 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 13:59:13 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	temp1[50] = "yeblee 101호";
	int		num = 2147483648;
	char	c = '\0';
	int		lhexa = 42;
	int		uhexa = 42;

	printf("in printff\ntemp is %s\n, number is %d\n, char is %c\n, percent is %%\n, lhexa = %x\n, uhexa = %X\n, pointer = %p, %p\n, next is newline\n" , temp1, num, c, lhexa, uhexa, NULL, 0);
	ft_printf("in ft_printf\ntemp is %s\n, number is %d\n, char is %c\n, percent is %%\n, lhexa = %x\n, uhexa = %X\n, pointer = %p, %p\n, next is newline\n" , temp1, num, c, lhexa, uhexa, NULL, 0);
	printf("printf: %c%c%c*", '\0', '1', 1);
	printf("\n------------------------------------\n");
	ft_printf("ft_printf: %c%c%c*", '\0', '1', 1);
	printf("\n------------------------------------\n");
	system("leaks a.out > leaks_result; cat leaks_result | \
	grep leaked && rm -rf leaks_result");
	return (0);
}
