/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:00:43 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/26 20:25:37 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	number_check(char *argv, int *values)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		error_free_int(BADLY_FORMATTED_ARG, values);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != '0')
			error_free_int(ARG_NOT_NUMBER, values);
		i++;
	}
}

static int	minmax_int_check(char *argv, int *values)
{
	long	converted_arg;

	if (ft_strlen(argv) > 11)
		error_free_int(NOT_INT_VALUE, values);
	converted_arg = ft_atolong(argv);
	if (converted_arg < MIN_INT || converted_arg > MAX_INT)
		error_free_int(NOT_INT_VALUE, values);
	return ((int)converted_arg);
}

static void	check_duplicated_value(int argc, char **argv, int *values)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atolong(argv[i]) == ft_atolong(argv[j]))
				error_free_int(DUPLICATED_VALUE, values);
			j++;
		}
		i++;
	}
}

int	*arg_check(int argc, char **argv)
{
	int	arg_counter;
	int	*arg_holder;
	int	i;

	if (argc < 2)
		exit(NULL_ARGS);
	arg_counter = 0;
	arg_holder = ft_calloc(argc - 1, sizeof(int *));
	i = -1;
	while (argv[++arg_counter] != NULL)
	{
		number_check(argv[arg_counter], arg_holder);
		arg_holder[++i] = minmax_int_check(argv[arg_counter],
				arg_holder);
	}
	check_duplicated_value(argc, argv, arg_holder);
	return (arg_holder);
}
