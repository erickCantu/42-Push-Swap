/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_selection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:54:46 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/14 18:41:25 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_solve(t_stack *stack_a, t_stack *stack_b, t_stack_solutions *sol,
		t_counters *count)
{
	int	i;

	ps_solve_stack_b(stack_a, stack_b, sol, count);
	i = 0;
	while (i < (count->stack_a_limit - 3))
	{
		ps_p(stack_b, stack_a, 'b');
		i++;
	}
	ps_solve_3_asc(stack_a, 'a');
	sol->run = 3;
	while (sol->run < count->stack_a_limit)
		ps_solve_stack_a_limit(count, sol, stack_a, stack_b);
	ps_solve_stack_a(*count, stack_a);
	ps_solve_return_to_stack_a(*count, stack_a, stack_b, *sol);
}

void	ps_solve_2(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->head->next->value)
		ps_s(stack_a, 'a');
	return ;
}

void	ps_solve_3_asc(t_stack *stack, char stack_name)
{
	if (!stack->head)
		return ;
	if (stack->stack_size == 3)
	{
		ps_solve_3_asc_algorithm(stack, stack_name);
	}
	else if (stack->head->next && stack->head->value > stack->head->next->value)
		ps_s(stack, stack_name);
	ps_reset_key(stack->head);
}

void	ps_solve_5(t_stack *stack_a, t_stack *stack_b, t_stack_solutions *sol,
		t_counters *count)
{
	if (ps_check_solution(*stack_a, *sol))
		return ;
	ps_p(stack_b, stack_a, 'b');
	ps_p(stack_b, stack_a, 'b');
	if (stack_b->head->value < stack_b->tail->value)
		ps_s(stack_b, 'b');
	ps_solve_3_asc(stack_a, 'a');
	sol->run = 3;
	count->stack_a_limit = 5;
	while (sol->run < count->stack_a_limit)
		ps_solve_stack_a_limit(count, sol, stack_a, stack_b);
	while (stack_a->tail->value < stack_a->head->value)
		ps_rr(stack_a, 'a');
}

void	ps_solve_selection(t_stack *stack_a, t_stack *stack_b,
		t_stack_solutions *sol, t_counters *count)
{
	if (stack_a->stack_size < 2 || ps_check_solution(*stack_a, *sol))
		return ;
	else if (stack_a->stack_size < 3)
		ps_solve_2(stack_a);
	else if (stack_a->stack_size < 4)
		ps_solve_3_asc(stack_a, 'a');
	else if (stack_a->stack_size < 6)
	{
		count->stack_a_limit = 5;
		ps_solve_5(stack_a, stack_b, sol, count);
	}
	else if (stack_a->stack_size < 24)
	{
		count->stack_a_limit = 5;
		ps_ini_sort_1_node(stack_b, stack_a);
		ps_solve(stack_a, stack_b, sol, count);
	}
	else
	{
		count->stack_a_limit = 23;
		ps_ini_sort_1_node(stack_b, stack_a);
		ps_solve(stack_a, stack_b, sol, count);
	}
}
