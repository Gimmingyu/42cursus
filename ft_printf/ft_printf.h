/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:06:29 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/14 16:45:16 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

# define NUL '\0'
# define HEXA "0123456789ABCDEF"

typedef void(*t_func)(char *);

typedef enum e_err
{
	OK = 1,
	ERR = -1,
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

size_t	get_strlen(const char *str);
size_t	get_int_malloc_size(int num);
size_t	get_ui_malloc_size(unsigned int num);
size_t	get_hexa_malloc_size(unsigned long long num);

char	*assign_result(char type, va_list *ap_ptr);
t_type	assign_func(void **fp_ptr, char type);

char	*char_conversion(va_list *ap_ptr);
char	*string_conversion(va_list *ap_ptr);
char	*ptr_conversion(va_list *ap_ptr);
char	*int_conversion(va_list *ap_ptr);
char	*ui_conversion(va_list *ap_ptr);
char	*lhexa_conversion(va_list *ap_ptr);
char	*uhexa_conversion(va_list *ap_ptr);

void	free_return_line(char **ret_ptr);

void	write_char(char *ret);
void	write_string(char *ret);
void	write_integer(char *ret);
void	write_pointer(char *ret);
void	write_lower_hexa(char *ret);
void	write_upper_hexa(char *ret);
void	write_unsigned_int(char *ret);
void	write_percent(char *ret);
#endif
