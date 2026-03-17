/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:21:10 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/14 14:49:25 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_initialize(t_stack *stack, int key, char *data)
{
	t_node	*node;

	if (!stack)
	{
		ps_initialize_stack(stack);
	}
	node = ps_initalizate_node(key, data);
	if (!node)
		return (-1);
	ps_add_tail(stack, node);
	return (0);
}

void	ps_initialize_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->current = NULL;
	stack->tail = NULL;
	stack->stack_size = 0;
	stack->avg = 0;
	stack->stdev = 0;
}

t_node	*ps_pop_bottom(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->tail;
	if (stack->head == stack->tail)
	{
		stack->head = NULL;
		stack->tail = NULL;
		return (tmp);
	}
	stack->tail->prev->next = NULL;
	stack->tail = stack->tail->prev;
	tmp->prev = NULL;
	return (tmp);
}

t_node	*ps_pop_top(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	if (stack->head == stack->tail)
	{
		stack->head = NULL;
		stack->tail = NULL;
		return (tmp);
	}
	stack->head->next->prev = NULL;
	stack->head = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

void	ps_stack_push(t_stack *stack, t_node *node)
{
	if (!stack->head)
		node->key = 0;
	if (stack->head)
	{
		node->key = stack->head->key + 1;
		node->next = stack->head;
		stack->head->prev = node;
	}
	stack->head = node;
	if (!stack->tail)
		stack->tail = node;
}
