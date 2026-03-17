/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_matrix_solution.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:33:08 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 13:45:17 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_solution(t_stack stack_a, t_stack_solutions sol)
{
	int	i;

	i = 0;
	while (i < sol.input_size)
	{
		if (sol.mtx[i][1] != stack_a.head->value)
		{
			return (0);
		}
		i++;
		stack_a.head = stack_a.head->next;
	}
	return (1);
}

static void	ps_mtx_solve_matrix(t_stack_solutions *sol)
{
	int	i;
	int	j;
	int	tmp[1][2];

	i = 1;
	while (i)
	{
		i = 0;
		j = 0;
		while (j < sol->input_size - 1)
		{
			if (sol->mtx[j][1] > sol->mtx[j + 1][1])
			{
				while (i < 2)
				{
					tmp[0][i] = sol->mtx[j][i];
					sol->mtx[j][i] = sol->mtx[j + 1][i];
					sol->mtx[j + 1][i] = tmp[0][i];
					i++;
				}
			}
			j++;
		}
	}
}

int	ps_mtx_sol(t_stack_solutions *sol)
{
	int	i;

	i = 0;
	sol->mtx = (int **)ft_calloc(sol->input_size + 1, sizeof(int *));
	if (!sol->mtx)
		return (-1);
	while (i < sol->input_size)
	{
		sol->mtx[i] = (int *)ft_calloc(2, sizeof(int));
		if (!sol->mtx[i])
		{
			ps_free((void **)sol->mtx);
			return (-1);
		}
		sol->mtx[i][0] = i;
		sol->mtx[i][1] = ft_atoi(sol->p_argv[i]);
		i++;
	}
	ps_mtx_solve_matrix(sol);
	return (0);
}
