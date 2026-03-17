/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_counters_selection.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:42:30 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:31:55 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_select_counters(t_counters *count, t_stack *stack_b, t_stacks *s)
{
	if (count->k != 0 && count->l != 0)
	{
		if (count->k > count->l)
			count->k = 0;
		else
			count->l = 0;
	}
	if (count->n != 0 && count->m != 0)
	{
		if (count->m > count->n)
			count->m = 0;
		else
			count->n = 0;
	}
	ps_select_counters_rrb(count, *stack_b, s);
}

void	ps_select_counters_rrb(t_counters *count, t_stack stack_b, t_stacks *s)
{
	if (count->l > 0 && count->l == count->n && count->l == stack_b.stack_size)
	{
		count->l = 0;
		count->n = 0;
		s->stack_b_rl = stack_b;
		s->stack_b_rn = stack_b;
		while (s->stack_b_rl.head->value < s->stack_b_rl.tail->value)
		{
			s->stack_b_rl.tail = s->stack_b_rl.tail->prev;
			count->n++;
		}
		while (s->stack_b_rn.head->value < s->stack_b_rn.tail->value)
		{
			s->stack_b_rn.tail = s->stack_b_rn.tail->prev;
			count->l++;
		}
		if (count->n < count->l)
			count->l = count->n;
		else
			count->n = count->l;
	}
}
