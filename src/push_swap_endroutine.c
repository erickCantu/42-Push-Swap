/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_endroutine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:37:50 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 13:41:58 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ps_clean(void **ptr, size_t ptr_len)
{
	while (ptr_len > 0)
	{
		ps_free((void **)(ptr + ptr_len - 1));
		ptr_len--;
	}
}

void	ps_stack_clean(t_stack *stack, void (*del)(void **))
{
	t_node	*tmp;

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

void	ps_endroutine(int argc, t_stack stack_a, t_stack stack_b,
		t_stack_solutions *sol)
{
	if (argc == 2)
	{
		ps_clean((void **)sol->p_argv, sol->input_size);
		ps_free((void **)sol->p_argv);
	}
	free(sol->p_argv);
	sol->p_argv = NULL;
	ps_clean((void **)sol->mtx, sol->input_size);
	ps_free((void **)sol->mtx);
	free(sol->mtx);
	sol->mtx = NULL;
	ps_stack_clean(&stack_a, ps_free);
	if (stack_b.head)
		ps_stack_clean(&stack_b, ps_free);
	if (sol)
		ps_clean_solution(sol, ps_free);
}
