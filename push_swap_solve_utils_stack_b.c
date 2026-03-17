/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_stack_b.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:26:59 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:42:38 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_solve_counter_stack_b(t_counters count, t_stack *stack_b)
{
	count.x = ps_sort_b_r(*stack_b);
	count.y = ps_sort_b_rr(*stack_b);
	if (count.x < count.y)
	{
		while (stack_b->tail->value > stack_b->head->value)
			ps_r(stack_b, 'b');
	}
	else
	{
		while (stack_b->tail->value > stack_b->head->value)
			ps_rr(stack_b, 'b');
	}
}

void	ps_solve_return_to_stack_a(t_counters count, t_stack *stack_a,
		t_stack *stack_b, t_stack_solutions sol)
{
	ps_solve_counter_stack_b(count, stack_b);
	while (stack_b->head)
	{
		if (stack_a->head && stack_a->tail->value > stack_b->head->value
			&& sol.run > 0)
		{
			ps_rr(stack_a, 'a');
			sol.run--;
		}
		else
			ps_p(stack_a, stack_b, 'a');
	}
	while (stack_a->head->value > stack_a->tail->value)
	{
		if (stack_a->head->value > stack_a->head->next->value)
			ps_r(stack_a, 'a');
		else
			ps_rr(stack_a, 'a');
	}
}

void	ps_sol_run(t_stack *stack_a, t_stack *stack_b, t_stack_solutions *sol)
{
	ps_select_solution(sol);
	if (sol->head && sol->head->sol_value < sol->steps_limits)
	{
		if (sol->head->sol == 'x')
			ps_xkl(stack_a, stack_b, sol);
		else
			ps_ymn(stack_a, stack_b, sol);
		ps_p(stack_b, stack_a, 'b');
		if (!ps_isinstdev(stack_a->head, sol->c_d))
			sol->cluster_counter++;
		sol->steps_limits = 9;
		if (sol->jumps > 1)
			sol->cluster_counter--;
		sol->jumps = 0;
	}
	else
	{
		if (sol->jumps > 0)
			sol->steps_limits = sol->input_size;
		else
		{
			sol->cluster_counter++;
			sol->jumps++;
		}
	}
}
