/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:42:17 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/26 19:51:37 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list_ps *list)
{
	int	max;

	max = get_max_value(list);
	while (is_organized(list) == FALSE)
	{
		if (list->head->value == max)
			rotate(list, "ra\n");
		else if (list->head->next->value == max)
			reverse_rotate(list, "rra\n");
		else
			swap(list, "sa\n");
	}
}

void	medium_sort(t_list_ps *stack_a, t_list_ps *stack_b)
{
	int	smallest_value;
	while (is_organized(stack_a) == FALSE && stack_a->size > 3)
	{
		smallest_value = get_min_value(stack_a);
		if (stack_a->head->value == smallest_value)
			push(stack_a, stack_b, "pb\n");
		else if (stack_a->head->next->value == smallest_value)
			swap(stack_a, "sa\n");
		else if (stack_a->tail->value == smallest_value)
			reverse_rotate(stack_a, "rra\n");
		else
		{
			rotate(stack_a, "ra\n");
			rotate(stack_a, "ra\n");
		}
	}
	if (is_organized(stack_a) == FALSE)
		sort(stack_a);
	while (stack_b->size != 0)
		push(stack_b, stack_a, "pa\n");
}

t_list_ps	*fake_sort(int *values, int v_len)
{
	t_list_ps	*copy_stack;
	t_list_ps	*sorted_stack;
	int			max_value;

	copy_stack = new_list();
	sorted_stack = new_list();
	list_fill(copy_stack, values, v_len);
	max_value = get_max_value(copy_stack);
	while (copy_stack->head)
	{
		if (copy_stack->head->value == max_value)
		{
			fake_push(copy_stack, sorted_stack);
			if (copy_stack->head)
				max_value = get_max_value(copy_stack);
		}
		else
			fake_rotate(copy_stack);
	}
	free_list(copy_stack);
	return (sorted_stack);
}

void	convert_to_index(t_list_ps *stack, int *values, int v_len)
{
	t_list_ps	*sorted_stack;
	t_node		*stack_node;
	t_node		*sorted_node;
	int			index;

	sorted_stack = fake_sort(values, v_len);
	stack_node = stack->head;
	while (stack_node)
	{
		sorted_node = sorted_stack->head;
		index = 0;
		while (index < stack->size)
		{
			if (stack_node->value == sorted_node->value)
				stack_node->value = index;
			sorted_node = sorted_node->next;
			index++;
		}
		stack_node = stack_node->next;
	}
	free_list(sorted_stack);
}

void	big_sort(t_list_ps *s_a, t_list_ps *s_b, int *values, int v_len)
{
	int	i;
	int	n;
	int	size;

	i = 1;
	size = s_a->size - 1;
	convert_to_index(s_a, values, v_len);
	while (is_organized(s_a) == FALSE)
	{
		n = 0;
		while (n++ < v_len - 1)
		{
			if ((s_a->head->value >> i)&1)
				rotate(s_a, "ra\n");
			else
			{
				push(s_a, s_b, "pb\n");
			}
		}	
		while (s_b->size)
			push(s_b, s_a, "pa\n");
		i++;
	}
	//test(s_a);
}
