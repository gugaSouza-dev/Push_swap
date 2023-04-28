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
	if (argc == 4)
		sort(stack_a);
	else if (argc < 7)
		medium_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, converted_args, argc);
	free_list(stack_a);
	free_list(stack_b);
	free(converted_args);
	return (0);
}
