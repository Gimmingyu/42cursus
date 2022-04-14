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
	char	input[100] = "temp is %s, number is %d, char is %c, next is newline\n";
	char	temp1[50] = "yeblee 101호";
	int		num = 42;
	char	c = 'q';

	ft_printf(input, temp1, num, c);
	// printf("hexa x = %x, hexa X = %X\n");
	return (0);
}
