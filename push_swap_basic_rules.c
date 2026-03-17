/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_basic_rules.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:10:06 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:45:57 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_p(t_stack *stack_dst, t_stack *stack_src, char stack_dest_name)
{
	t_node	*tmp_src;

	if (!stack_src->head)
		return ;
	tmp_src = ps_pop_top(stack_src);
	ps_stack_push(stack_dst, tmp_src);
	ps_reset_key(stack_dst->head);
	ps_reset_key(stack_src->head);
	tmp_src = NULL;
	if (stack_dest_name)
		ft_printf("p%c\n", stack_dest_name);
	stack_dst->stack_size++;
	stack_src->stack_size--;
}

void	ps_r(t_stack *stack, char stack_name)
{
	t_node	*tmp_top;

	if (!stack->head)
		return ;
	tmp_top = ps_pop_top(stack);
	tmp_top->prev = stack->tail;
	stack->tail->next = tmp_top;
	stack->tail = tmp_top;
	ps_reset_key(stack->head);
	tmp_top = NULL;
	if (stack_name)
		ft_printf("r%c\n", stack_name);
}

void	ps_rr(t_stack *stack, char stack_name)
{
	t_node	*tmp_bottom;

	if (!stack->head)
		return ;
	tmp_bottom = ps_pop_bottom(stack);
	ps_reverse_reset_key(stack->tail);
	ps_stack_push(stack, tmp_bottom);
	tmp_bottom = NULL;
	if (stack_name)
		ft_printf("rr%c\n", stack_name);
}

void	ps_s(t_stack *stack, char stack_name)
{
	t_node	*tmp;

	if (!stack->head && !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = NULL;
	tmp->next = stack->head->next;
	stack->head->prev = tmp->prev;
	tmp->prev = stack->head;
	if (stack->head->next)
		stack->head->next->prev = tmp;
	stack->head->next = tmp;
	tmp = NULL;
	if (stack->stack_size == 2)
	{
		stack->current = stack->head;
		while (stack->head->next)
			stack->head = stack->head->next;
		stack->tail = stack->head;
		stack->head = stack->current;
		stack->current = NULL;
	}
	if (stack_name)
		ft_printf("s%c\n", stack_name);
}
