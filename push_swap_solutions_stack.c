/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solutions_stack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:37:51 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:44:15 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_add_tail_solution(t_stack_solutions *stack, t_node_solution *node)
{
	if (stack->head == NULL)
	{
		stack->head = node;
	}
	else
	{
		stack->tail->next = node;
	}
	node->prev = stack->tail;
	stack->tail = node;
	stack->stack_size += 1;
}

void	ps_clean_solution(t_stack_solutions *stack, void (*del)(void **))
{
	t_node_solution	*tmp;

	if (!stack)
		return ;
	while (stack->head)
	{
		tmp = stack->head->next;
		del((void **)&stack->head);
		stack->head = tmp;
		stack->stack_size--;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->stack_size = -1;
	stack->current = NULL;
}

void	ps_ini_solution_stack(t_stack_solutions *stack, t_counters count)
{
	t_node_solution	*node;

	if (!stack)
	{
		ps_initialize_stack_solution(stack);
	}
	node = ps_ini_solution_node(count);
	ps_add_tail_solution(stack, node);
}

void	ps_initialize_stack_solution(t_stack_solutions *stack)
{
	stack->c_d = 0;
	stack->cluster_counter = -5;
	stack->current = NULL;
	stack->head = NULL;
	stack->input_size = 0;
	stack->jumps = 0;
	stack->mtx = NULL;
	stack->p_argv = NULL;
	stack->run = 0;
	stack->steps_limits = 9;
	stack->stack_size = 0;
	stack->tail = NULL;
}

void	ps_sort_solution(t_stack_solutions *statck)
{
	t_node_solution	*tmp;

	if (!statck->head && !statck->head->next)
		return ;
	tmp = statck->head;
	statck->head = statck->head->next;
	tmp->next = NULL;
	tmp->next = statck->head->next;
	statck->head->prev = tmp->prev;
	tmp->prev = statck->head;
	if (statck->head->next)
		statck->head->next->prev = tmp;
	statck->head->next = tmp;
	tmp = NULL;
}
