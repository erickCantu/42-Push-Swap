/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:01:27 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:43:31 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_solve_3_asc_algorithm(t_stack *stack, char stack_name)
{
	if (stack->head->value < stack->head->next->value)
	{
		if (stack->head->next->value < stack->head->next->next->value)
			return ;
		else if (stack->head->value < stack->head->next->next->value)
		{
			ps_r(stack, stack_name);
			ps_s(stack, stack_name);
			ps_rr(stack, stack_name);
		}
		else
			ps_rr(stack, stack_name);
	}
	else if (stack->head->value < stack->head->next->next->value)
		ps_s(stack, stack_name);
	else if (stack->head->next->value < stack->head->next->next->value)
		ps_r(stack, stack_name);
	else
	{
		ps_s(stack, stack_name);
		ps_rr(stack, stack_name);
	}
}

void	ps_isrun(t_counters *count, t_stack *stack_b, t_stack_solutions *sol,
		t_stacks *s)
{
	while (s->stack_a_r.head)
	{
		if (ps_solve_counters(s, count, sol) != 0)
			continue ;
		ps_select_counters(count, stack_b, s);
		ps_ini_solution_stack(sol, *count);
		if (ps_isfound_solution(count, stack_b, s) != 0)
			break ;
	}
}

void	ps_solve_stack_a_limit(t_counters *count, t_stack_solutions *sol,
		t_stack *stack_a, t_stack *stack_b)
{
	count->k = ps_compare_k_m_reverse(stack_b->head->value, *stack_a);
	count->l = ps_compare_l_n_reverse(stack_b->head->value, *stack_a);
	if (count->k || count->l)
	{
		if (count->k < count->l)
		{
			while (count->k > 0)
			{
				ps_r(stack_a, 'a');
				count->k--;
			}
		}
		else
		{
			while (count->l > 0)
			{
				ps_rr(stack_a, 'a');
				count->l--;
			}
		}
	}
	ps_p(stack_a, stack_b, 'a');
	sol->run++;
}

void	ps_solve_stack_a(t_counters count, t_stack *stack_a)
{
	count.x = ps_sort_a_r(*stack_a);
	count.y = ps_sort_a_rr(*stack_a);
	if (count.x < count.y)
	{
		while (stack_a->tail->value < stack_a->head->value)
			ps_r(stack_a, 'a');
	}
	else
	{
		while (stack_a->tail->value < stack_a->head->value)
			ps_rr(stack_a, 'a');
	}
}

void	ps_solve_stack_b(t_stack *stack_a, t_stack *stack_b,
		t_stack_solutions *sol, t_counters *count)
{
	t_stacks	s;

	while (stack_a->stack_size > count->stack_a_limit)
	{
		ps_sol_ini(stack_a, sol, count);
		ps_initialize_stacks(&s, stack_a, stack_b);
		if (stack_a->head->value > stack_b->head->value
			&& stack_a->head->value > stack_b->tail->value
			&& stack_b->head->value > stack_b->tail->value
			&& (stack_a->head->value <= sol->c_d))
			sol->run = 1;
		else
			ps_isrun(count, stack_b, sol, &s);
		if (!sol->run)
			ps_sol_run(stack_a, stack_b, sol);
		else
		{
			ps_p(stack_b, stack_a, 'b');
			if (!ps_isinstdev(stack_a->head, sol->c_d))
				sol->cluster_counter++;
		}
		ps_clean_solution(sol, ps_free);
	}
}
