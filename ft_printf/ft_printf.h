/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:06:29 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 14:20:39 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "./libft/libft.h"

# define NUL '\0'
# define UHEXA_BASE "0123456789ABCDEF"
# define LHEXA_BASE "0123456789abcdef"
# define BASE "0123456789"
typedef ssize_t(*t_func)(va_list *);

typedef enum e_err
{
	OK = 1,
	ERR = 0,
}	t_err;

typedef enum e_type
{
	CHAR = 'c',
	STRING = 's',
	DIGIT = 'd',
	INT = 'i',
	POINTER = 'p',
	LOWER_HEXA = 'x',
	UPPER_HEXA = 'X',
	UNSIGNED_INT = 'u',
	PERCENT = '%',
	INVALID = NUL,
}	t_type;

int		ft_printf(const char *input, ...);
int		get_strlen(const char *str);

size_t	get_int_malloc_size(int num);
size_t	get_ui_malloc_size(unsigned int num);
size_t	get_hexa_malloc_size(unsigned int num);
size_t	get_ptr_malloc_size(unsigned long long num);

char	*assign_result(char type, va_list *ap_ptr);
int		assign_func(void **fp_ptr, char type);

int		conversion_int(va_list *ap_ptr);
int		conversion_uint(va_list *ap_ptr);
int		conversion_lhexa(va_list *ap_ptr);
int		conversion_uhexa(va_list *ap_ptr);
int		conversion_percent(void);
int		conversion_ptr(va_list *ap_ptr);
int		conversion_char(va_list *ap_ptr);
int		conversion_string(va_list *ap_ptr);

#endif
