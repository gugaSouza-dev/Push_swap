/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_moviments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 02:51:06 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/26 20:05:28 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	super_swap(t_list_ps *list_a, t_list_ps *list_b)
{
	swap(list_a, NULL);
	swap(list_b, NULL);
	write(1, "ss\n", 3);
}

void	super_rotate(t_list_ps *stack_a, t_list_ps *stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	write(1, "rr\n", 3);
}

void	super_reverse_rotate(t_list_ps *stack_a, t_list_ps *stack_b)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	write(1, "rrr\n", 4);
}
