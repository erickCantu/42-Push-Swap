/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solutions_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:02:49 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:43:57 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_solution	*ps_ini_solution_node(t_counters count)
{
	t_node_solution	*node;

	node = (t_node_solution *)malloc(sizeof(t_node_solution));
	if (!node)
		return (NULL);
	node->key = count.i;
	node->k = count.k;
	node->l = count.l;
	node->m = count.m;
	node->n = count.n;
	node->x = count.x;
	node->y = count.y;
	if (count.x + count.k + count.l < count.y + count.m + count.n)
	{
		node->sol_value = (count.x + count.k + count.l);
		node->sol = 'x';
	}
	else
	{
		node->sol_value = (count.y + count.m + count.n);
		node->sol = 'y';
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ps_reset_key(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->key = i;
		i++;
		stack = stack->next;
	}
}

void	ps_reverse_reset_key(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->key = i;
		i++;
		stack = stack->prev;
	}
}
