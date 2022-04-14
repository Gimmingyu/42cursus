/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:40:02 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/14 13:53:14 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	input[43] = "temp is %s, number is %d, next is newline\n";
	char	temp1[250] = "yeblee 101호";
	// char	temp2[250] = "tkang 2호";
	char	temp3[250] = "tkang 3호";
	char	temp4[250] = "tkang 4호";
	char	temp5[250] = "tkang 5호";
	char	temp6[250] = "tkang 6호";
	char	temp7[250] = "tkang 7호";
	char	temp8[250] = "tkang 8호";
	char	temp9[250] = "tkang 9호";
	char	temp10[250] = "tkang 10호";
	int		num = 42;

	ft_printf(input, temp1, num, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10);
	// printf("hexa x = %x, hexa X = %X\n");
	return (0);
}
