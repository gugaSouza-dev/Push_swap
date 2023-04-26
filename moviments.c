/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:38:45 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/26 20:05:49 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list_ps *list, char *moviment)
{
	int		value_holder;
	t_node	*head;

	head = list->head;
	write(1, moviment, 3);
	value_holder = head->value;
	head->value = head->next->value;
	head->next->value = value_holder;
}

void	push(t_list_ps *src, t_list_ps *dest, char *moviment)
{
	t_node	*temp;

	if (src->head == NULL)
		return ;
	write(1, moviment, 3);
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

void	rotate(t_list_ps *list, char *moviment)
{
	t_node	*head;
	t_node	*tail;
	t_node	*next;

	head = list->head;
	tail = list->tail;
	next = head->next;
	if (head == NULL)
		return ;
	write(1, moviment, 3);
	list->head = next;
	next->prev = NULL;
	list->tail->next = head;
	list->tail = head;
	head->next = NULL;
	head->prev = tail;
}

void	reverse_rotate(t_list_ps *list, char *moviment)
{
	t_node	*head;
	t_node	*tail;
	t_node	*last_but_one;

	head = list->head;
	tail = list->tail;
	last_but_one = list->tail->prev;
	if (!tail)
		return ;
	write(1, moviment, 4);
	list->tail = last_but_one;
	last_but_one->next = NULL;
	tail->prev = NULL;
	list->head = tail;
	tail->next = head;
	head->prev = tail;
}
