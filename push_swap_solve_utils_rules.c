/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_rules.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:05:45 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:43:06 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_a_r(t_stack stack)
{
	int	x;

	x = 0;
	while (stack.head->value > stack.tail->value)
	{
		stack.head = stack.head->next;
		x++;
	}
	return (x);
}

int	ps_sort_b_r(t_stack stack)
{
	int	x;

	x = 0;
	while (stack.head->value < stack.tail->value)
	{
		stack.head = stack.head->next;
		x++;
	}
	return (x);
}

int	ps_sort_a_rr(t_stack stack)
{
	int	y;

	y = 0;
	while (stack.head->value > stack.tail->value)
	{
		stack.tail = stack.tail->prev;
		y++;
	}
	return (y);
}

int	ps_sort_b_rr(t_stack stack)
{
	int	y;

	y = 0;
	while (stack.head->value < stack.tail->value)
	{
		stack.tail = stack.tail->prev;
		y++;
	}
	return (y);
}
