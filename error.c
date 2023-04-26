/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:02:15 by gusouza-          #+#    #+#             */
/*   Updated: 2023/04/25 15:19:19 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int exit_code)
{
	ft_putstr_fd("Error\n", 1);
	exit(exit_code);
}

void	error_free_int(int exit_code, int *values)
{
	free(values);
	error(exit_code);
}
