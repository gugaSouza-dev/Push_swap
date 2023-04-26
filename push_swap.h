/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:32:57 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/26 19:55:21 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0

# define NULL_ARGS 10
# define BADLY_FORMATTED_ARG 11
# define ARG_NOT_NUMBER 12
# define NOT_INT_VALUE 13
# define STACK_FAIL 14
# define MALLOC_ERROR 15
# define DUPLICATED_VALUE 16
# define VALUES_ARE_ORGANIZED 17

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	// int				stack_position;
	int				value;
}	t_node;

typedef struct s_list_ps
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_list_ps;

void		add_head(t_list_ps *list, int value);
void		add_tail(t_list_ps *list, int value);
void		error(int exit_code);
void		error_free_int(int exit_code, int *values);
void		free_list(t_list_ps *list);
void		list_fill(t_list_ps *list, int *values, int values_len);
int			is_organized(t_list_ps *list);
int			*arg_check(int argc, char **argv);
t_list_ps	*new_list(void);

//moviments
void		swap(t_list_ps *list, char *moviment);
void		super_swap(t_list_ps *list_a, t_list_ps *list_b);
void		push(t_list_ps *src, t_list_ps *dest, char *moviment);
void		rotate(t_list_ps *list, char *moviment);
void		super_rotate(t_list_ps *list_a, t_list_ps *list_b);
void		reverse_rotate(t_list_ps *list, char *moviment);
void		super_reverse_rotate(t_list_ps *stack_a, t_list_ps *stack_b);

//utils
int			get_max_value(t_list_ps *list);
int			get_min_value(t_list_ps *list);
void		fake_push(t_list_ps *src, t_list_ps *dest);
void		fake_rotate(t_list_ps *list);

//sort
void		sort(t_list_ps *list);
void		medium_sort(t_list_ps *list_a, t_list_ps *list_b);
void		big_sort(t_list_ps *s_a, t_list_ps *s_b, int *values, int v_len);

void		test(t_list_ps *list);

// void	init_stack(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
#endif