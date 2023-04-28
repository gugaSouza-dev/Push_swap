/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:27:58 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/26 19:47:46 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_organized(t_list_ps *list)
{
	t_node	*node;

	node = list->head;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

int	get_max_value(t_list_ps *list)
{
	int		max;
	t_node	*node;

	max = list->head->value;
	node = list->head;
	while (node)
	{
		if (max < node->value)
			max = node->value;
		else
			node = node->next;
	}
	return (max);
}

int	get_min_value(t_list_ps *list)
{
	int		min;
	t_node	*node;

	min = MAX_INT - 1;
	node = list->head;
	while (node)
	{
		if (min > node->value)
			min = node->value;
		else
			node = node->next;
	}
	return (min);
}

void	fake_push(t_list_ps *src, t_list_ps *dest)
{
	t_node	*temp;

	if (src->head == NULL)
		return ;
	add_head(dest, src->head->value);
	if (src->size == 1)
	{
		free (src->head);
		src->head = NULL;
		src->tail = NULL;
		src->size--;
		return ;
	}
	temp = src->head;
	src->head = src->head->next;
	src->head->prev = NULL;
	free(temp);
	src->size--;
}

void	fake_rotate(t_list_ps *list)
{
	t_node	*head;
	t_node	*tail;
	t_node	*next;

	head = list->head;
	tail = list->tail;
	next = head->next;
	if (head == NULL)
		return ;
	list->head = next;
	next->prev = NULL;
	list->tail->next = head;
	list->tail = head;
	head->next = NULL;
	head->prev = tail;
}
