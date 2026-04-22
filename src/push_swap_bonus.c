/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:37:24 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/14 18:03:55 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_check_solution_bonus(t_stack stack_a, t_stack_solutions sol)
{
	if (ps_check_solution(stack_a, sol))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_counters			count;
	t_stack				stack_a;
	t_stack				stack_b;
	t_stack_solutions	sol;

	if (argc < 2)
		return (0);
	ps_initialize_stack(&stack_a);
	ps_initialize_stack(&stack_b);
	ps_initialize_stack_solution(&sol);
	ps_initialize_counters(&count);
	if (ps_initialize_p_argv(&sol, argc, argv) != 0)
		return (-1);
	while (++count.i < sol.input_size)
	{
		if (ps_initialize(&stack_a, count.i, *(sol.p_argv + count.i)) != 0)
			return (ps_error("Error", sol.p_argv, sol.input_size));
	}
	ps_initialize_avg_std(&stack_a, &stack_b, sol.mtx);
	ps_solve_selection(&stack_a, &stack_b, &sol, &count);
	ps_check_solution_bonus(stack_a, sol);
	ps_endroutine(argc, stack_a, stack_b, &sol);
	return (0);
}
