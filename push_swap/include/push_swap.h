/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:26:11 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/08 17:22:23 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef enum e_type
{
	OK = 1,
	FALSE = 0,
	ERROR = -1,
}	t_type;

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_linked_stack
{
	size_t			element_count;
	t_stack_node	top_node;
}	t_linked_stack;

typedef struct s_res_list
{
	size_t				length;
	char				*res;
	struct s_res_list	*next;
}	t_res_list;

int				is_linked_stack_empty(t_linked_stack *stack);
void			create_stacks(t_linked_stack **a_ptr, t_linked_stack **b_ptr);
t_stack_node	*create_node(int value);

int				push_bottom(t_linked_stack *stack, int value);
int				push_top(t_linked_stack *stack, t_stack_node node);
t_stack_node	*pop_on_top(t_linked_stack *stack);
int				push(t_linked_stack *push_stack, t_linked_stack *pop_stack);

int				single_swap(t_linked_stack *stack);
int				both_swap(t_linked_stack *a_stack, t_linked_stack *b_stack);
int				is_swap_exception(t_linked_stack *a_stack);

int				single_rotate(t_linked_stack *stack);
int				both_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack);

int				delete_stack(t_linked_stack *a_stack, t_linked_stack *b_stack);
void			display_stack(t_linked_stack *stack);
long long		a_to_longlong(const char *str);
int				is_greater(int a, int b);
int				is_sorted(t_linked_stack *stack);

int				response_error(void);

void			check_is_integer(int ac, char **av);
void			check_is_duplicate(int ac, char **av);
void			validator(int ac, char **av);

int				solution(t_linked_stack *a_stack, t_linked_stack *b_stack);
#endif