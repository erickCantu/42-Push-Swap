/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solutions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:44:29 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:42:36 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_select_solution(t_stack_solutions *stack)
{
	if (stack->head == stack->tail)
		return ;
	stack->counter = 1;
	while (stack->counter)
	{
		stack->counter = 0;
		while (stack->head->next)
		{
			if (stack->head->next
				&& stack->head->sol_value > stack->head->next->sol_value)
			{
				stack->counter++;
				ps_sort_solution(stack);
			}
			if (stack->head->next)
				stack->head = stack->head->next;
		}
		stack->tail = stack->head;
		while (stack->head->prev)
		{
			stack->head->prev->next = stack->head;
			stack->head = stack->head->prev;
		}
	}
}

int	ps_isfound_solution(t_counters *count, t_stack *stack_b, t_stacks *s)
{
	if (s->stack_a_r.head->key >= s->stack_a_rr.tail->key)
		return (-1);
	s->stack_a_r.head = s->stack_a_r.head->next;
	s->stack_a_rr.tail = s->stack_a_rr.tail->prev;
	s->stack_b_rk = *stack_b;
	s->stack_b_rl = *stack_b;
	s->stack_b_rm = *stack_b;
	s->stack_b_rn = *stack_b;
	ps_advance_solution(count);
	return (0);
}

void	ps_xkl(t_stack *stack_a, t_stack *stack_b, t_stack_solutions *sol)
{
	while (sol->head->x > 0 && sol->head->k > 0)
	{
		ps_rab(stack_a, stack_b);
		sol->head->x--;
		sol->head->k--;
	}
	while (sol->head->x > 0)
	{
		ps_r(stack_a, 'a');
		sol->head->x--;
	}
	while (sol->head->k > 0)
	{
		ps_r(stack_b, 'b');
		sol->head->k--;
	}
	while (sol->head->l > 0)
	{
		ps_rr(stack_b, 'b');
		sol->head->l--;
	}
}

void	ps_ymn(t_stack *stack_a, t_stack *stack_b, t_stack_solutions *sol)
{
	while (sol->head->y > 0 && sol->head->n > 0)
	{
		ps_rrab(stack_a, stack_b);
		sol->head->y--;
		sol->head->n--;
	}
	while (sol->head->y > 0)
	{
		ps_rr(stack_a, 'a');
		sol->head->y--;
	}
	while (sol->head->m > 0)
	{
		ps_r(stack_b, 'b');
		sol->head->m--;
	}
	while (sol->head->n > 0)
	{
		ps_rr(stack_b, 'b');
		sol->head->n--;
	}
}
