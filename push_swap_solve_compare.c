/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_compare.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:09:02 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:41:50 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_compare_k_m(int a, t_stack stack_b)
{
	int	counter;
	int	k;

	k = 0;
	counter = stack_b.stack_size;
	while (--counter > 0)
	{
		if ((a > stack_b.head->value && a < stack_b.tail->value)
			|| (a < stack_b.head->value && a < stack_b.tail->value
				&& stack_b.head->value > stack_b.tail->value)
			|| (a > stack_b.head->value && a > stack_b.tail->value
				&& stack_b.head->value > stack_b.tail->value))
			return (k);
		stack_b.tail = stack_b.head;
		stack_b.head = stack_b.head->next;
		k++;
	}
	return (k);
}

int	ps_compare_k_m_reverse(int a, t_stack stack)
{
	int	counter;
	int	k;

	k = 0;
	counter = stack.stack_size;
	while (--counter > 0)
	{
		if ((a < stack.head->value && a > stack.tail->value)
			|| (a > stack.head->value && a > stack.tail->value
				&& stack.head->value < stack.tail->value)
			|| (a < stack.head->value && a < stack.tail->value
				&& stack.head->value < stack.tail->value))
			return (k);
		stack.tail = stack.head;
		stack.head = stack.head->next;
		k++;
	}
	return (k);
}

int	ps_compare_l_n(int a, t_stack stack_b)
{
	int	counter;
	int	l;

	l = 0;
	counter = stack_b.stack_size;
	while (--counter > 0)
	{
		if ((a > stack_b.head->value && a < stack_b.tail->value)
			|| (a < stack_b.head->value && a < stack_b.tail->value
				&& stack_b.head->value > stack_b.tail->value)
			|| (a > stack_b.head->value && a > stack_b.tail->value
				&& stack_b.head->value > stack_b.tail->value))
			return (l);
		stack_b.head = stack_b.tail;
		stack_b.tail = stack_b.tail->prev;
		l++;
	}
	return (l);
}

int	ps_compare_l_n_reverse(int a, t_stack stack)
{
	int	counter;
	int	l;

	l = 0;
	counter = stack.stack_size;
	while (--counter > 0)
	{
		if ((a < stack.head->value && a > stack.tail->value)
			|| (a > stack.head->value && a > stack.tail->value
				&& stack.head->value < stack.tail->value)
			|| (a < stack.head->value && a < stack.tail->value
				&& stack.head->value < stack.tail->value))
			return (l);
		stack.head = stack.tail;
		stack.tail = stack.tail->prev;
		l++;
	}
	return (l);
}

int	ps_isinstdev(t_node *stack_a, int std)
{
	while (stack_a)
	{
		if (stack_a->value < std)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
