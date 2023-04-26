/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 06:18:52 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/25 18:07:15 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_head(t_list_ps *list, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		exit(MALLOC_ERROR);
	node->prev = NULL;
	node->value = value;
	list->size += 1;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		node->next = NULL;
		return ;
	}
	list->head->prev = node;
	node->next = list->head;
	list->head = node;
}

void	add_tail(t_list_ps *list, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		exit(MALLOC_ERROR);
	node->next = NULL;
	node->value = value;
	list->size += 1;
	if (list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
		node->prev = NULL;
		return ;
	}
	list->tail->next = node;
	node->prev = list->tail;
	list->tail = node;
}

void	free_list(t_list_ps *list)
{
	t_node	*node;
	t_node	*del;

	node = list->tail;
	while (node)
	{
		del = node;
		node = node->prev;
		free(del);
	}
	free(list);
}

void	list_fill(t_list_ps *list, int *values, int values_len)
{
	int		i;

	i = -1;
	while (--values_len)
	{
		i++;
		if (i == 0)
			add_head(list, values[i]);
		else
			add_tail(list, values[i]);
	}
}

t_list_ps	*new_list(void)
{
	t_list_ps	*new_list;

	new_list = malloc(sizeof(t_list_ps));
	if (new_list == NULL)
		exit(MALLOC_ERROR);
	new_list->size = 0;
	new_list->head = NULL;
	new_list->tail = NULL;
	return (new_list);
}
