/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:32:46 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/26 19:57:26 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_list_ps *list)
{
	t_node *temp;
	temp = list->head;
	if (!list->head)
	{
		ft_printf("--EMPTY\n");
		return ;
	}
	while (temp != NULL)
	{
		ft_printf("%i\n", temp->value);
		temp = temp->next;
	}
	ft_printf("--DONE--\n");
}

int	main(int argc, char **argv)
{
	int			*converted_args;
	t_list_ps	*stack_a;
	t_list_ps	*stack_b;

	converted_args = arg_check(argc, argv);
	stack_a = new_list();
	stack_b = new_list();
	list_fill(stack_a, converted_args, argc);
	if (is_organized(stack_a) == TRUE)
	{
		free_list(stack_a);
		free_list(stack_b);
		free(converted_args);
		return (0);
	}

	// swap(stack_a, "SA\n");

	// push(stack_a, stack_b, "PB\n");
	// push(stack_b, stack_a, "PA\n");

	// rotate(stack_a, "RA\n");
	// super_rotate(stack_a, stack_b);

	// reverse_rotate(stack_a, "RRA\n");
	// super_reverse_rotate(stack_a, stack_b);

	// ft_printf("teste A:\n");
	// test(stack_a);
	// ft_printf("teste B:\n");
	// test(stack_b);

	// ft_printf("max %i\n", get_max_value(stack_a));
	// ft_printf("min: %i\n", get_min_value(stack_a));

	// ft_printf("%i\n", is_organized(stack_a));
	if (argc == 4)
		sort(stack_a);
	else if (argc < 7)
		medium_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, converted_args, argc);
	// push(stack_a, stack_b, "PB\n");
	// push(stack_a, stack_b, "PB\n");
	// push(stack_a, stack_b, "PB\n");
	// test(stack_a);
	// test(stack_b);

	// ft_printf("organized %i\n", (is_organized(stack_a)));

	free_list(stack_a);
	free_list(stack_b);
	free(converted_args);
	return (0);
}
