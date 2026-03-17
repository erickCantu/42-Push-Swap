/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_counters.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:53:16 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:46:42 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_advance_solution(t_counters *counters)
{
	counters->i++;
	counters->x++;
	counters->y++;
	counters->k = 0;
	counters->l = 0;
	counters->m = 0;
	counters->n = 0;
}

void	ps_initialize_counters(t_counters *count)
{
	count->i = -1;
	count->k = 0;
	count->l = 0;
	count->m = 0;
	count->n = 0;
	count->x = 0;
	count->y = 1;
}

void	ps_initialize_stacks(t_stacks *s, t_stack *stack_a, t_stack *stack_b)
{
	s->stack_a_r = *stack_a;
	s->stack_a_rr = *stack_a;
	s->stack_b_rk = *stack_b;
	s->stack_b_rl = *stack_b;
	s->stack_b_rm = *stack_b;
	s->stack_b_rn = *stack_b;
}

int	ps_solve_counters(t_stacks *s, t_counters *count, t_stack_solutions *sol)
{
	while (s->stack_a_r.head && (s->stack_a_r.head->value > sol->c_d))
	{
		s->stack_a_r.head = s->stack_a_r.head->next;
		count->x++;
	}
	if (!s->stack_a_r.head)
	{
		sol->cluster_counter++;
		return (-1);
	}
	while (s->stack_a_rr.tail && (s->stack_a_rr.tail->value > sol->c_d))
	{
		s->stack_a_rr.tail = s->stack_a_rr.tail->prev;
		count->y++;
	}
	count->k = ps_compare_k_m(s->stack_a_r.head->value, s->stack_b_rk);
	count->l = ps_compare_l_n(s->stack_a_r.head->value, s->stack_b_rl);
	count->m = ps_compare_k_m(s->stack_a_rr.tail->value, s->stack_b_rm);
	count->n = ps_compare_l_n(s->stack_a_rr.tail->value, s->stack_b_rn);
	return (0);
}
