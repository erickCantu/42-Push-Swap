/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:19:36 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 12:28:53 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_add_head(t_stack *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		stack->tail = node;
		node->next = NULL;
	}
	else
	{
		node->next = stack->head;
	}
	stack->head = node;
	stack->stack_size += 1;
}

void	ps_add_tail(t_stack *stack, t_node *node)
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

t_node	*ps_initalizate_node(int key, char *data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->key = key;
	node->data = data;
	node->value = ft_atoi(data);
	node->move = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ps_node_clean(t_node **node, void (*del)(void **))
{
	if (!node)
		return ;
	del((void **)node);
}

t_node	*ps_node_last(t_node *list)
{
	while (list != NULL && list->next != NULL)
	{
		list = list->next;
	}
	return (list);
}
