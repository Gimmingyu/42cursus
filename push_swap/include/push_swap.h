/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:26:11 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/12 17:27:10 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum e_type
{
	OK = 1,
	FALSE = 0,
	ERROR = -1,
}	t_type;

typedef enum e_command
{
	PA = 1,
	PB = 2,
	RA = 3,
	RB = 4,
	RRA = 5,
	RRB = 6,
	SA = 7,
	SB = 8,
}	t_command;

typedef struct s_stack_node
{
	int					value;
	size_t				target_idx;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_linked_stack
{
	size_t			element_count;
	t_stack_node	top_node;
}	t_linked_stack;

typedef struct s_information
{
	int			pivot_a;
	int			pivot_b;
}	t_info;

/* 
Function : Function for stack
*/
t_stack_node	*create_node(int value, size_t idx);
void			create_stacks(t_linked_stack **a_ptr, t_linked_stack **b_ptr);
void			display_stack(t_linked_stack *stack);
int				copy_stack(t_linked_stack *stack, t_linked_stack **stack_ptr);
int				is_linked_stack_empty(t_linked_stack *stack);
int				delete_all_stack(t_linked_stack *a_stack, \
									t_linked_stack *b_stack);
int				delete_single_stack(t_linked_stack *stack);
t_stack_node	*copy_node(t_stack_node *node);
/* 
Function : Function for stack action, push
*/
t_stack_node	*pop_on_top(t_linked_stack *stack);
t_stack_node	*pop_on_bottom(t_linked_stack *stack);
int				push_top(t_linked_stack *stack, int value, size_t idx);
int				push_bottom(t_linked_stack *stack, int value, size_t idx);
int				push(t_linked_stack *push_stack, t_linked_stack *pop_stack);

/* 
Function : Function for stack action, swap
*/
int				single_swap(t_linked_stack *stack);
int				both_swap(t_linked_stack *a_stack, t_linked_stack *b_stack);
int				is_swap_exception(t_linked_stack *a_stack);
/* 
Function : Function for stack actiom, reverse rotate
*/
int				single_reverse_rotate(t_linked_stack *stack);
int				both_reverse_rotate(t_linked_stack *a_stack, \
										t_linked_stack *b_stack);
/* 
Function : Function for stack action, rotate
*/
int				single_rotate(t_linked_stack *stack);
int				both_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack);
/* 
Function : Function for optimazation
*/
int				opt_three(t_linked_stack *stack);
int				opt_two(t_linked_stack *stack);
/* 
Function : Function for utility
*/
long long		a_to_longlong(const char *str);
int				is_greater(int a, int b);
int				get_sum_of_stack(t_linked_stack *stack);
// size_t			ft_strlen(const char *str);
/* 
Function : Function for response
*/
int				response_error(void);
/* 
Function : Function for validation
*/
void			check_is_integer(int ac, char **av);
void			check_is_duplicate(int ac, char **av);
void			validator(int ac, char **av, \
							t_linked_stack *a_stack, t_linked_stack *b_stack);
/* 
Function : Function for mapping information
*/
t_info			*create_info(int pivot_a, int pivot_b);
/*
Function: Function for sort
*/
int				solution(t_linked_stack *a_stack, t_linked_stack *b_stack);
int				select_pivot(t_linked_stack *stack, \
								int *pivot_a_ptr, int *pivot_b_ptr);
void			bubble_sort(t_linked_stack *stack);
int				set_index(t_linked_stack *stack, t_linked_stack *copied);
int				is_sorted(t_linked_stack *stack);
int				find_min_value(t_linked_stack *stack, int key);
int				step_one(t_linked_stack *a_stack, t_linked_stack *b_stack, \
							t_info *info);
int				step_two(t_linked_stack *a_stack, t_linked_stack *b_stack, \
							t_info *info);
int				step_three(t_linked_stack *a_stack, t_linked_stack *b_stack, \
							t_info *info);
size_t			get_max_value_index(t_linked_stack *stack);
/*
Function: Function for free
*/
int				free_struct_helper(t_info *info, t_type flag);
#endif