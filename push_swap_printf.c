/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 18:49:38 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 12:04:13 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_display_values(char *argv[])
{
	size_t	i;
	size_t	size;

	size = ps_dptrlen((const char **)argv);
	i = -1;
	while (++i < size)
	{
		ft_printf("%s   ", argv[i]);
	}
	ft_printf("\n");
}

void	ps_printf_stack(t_node *stack)
{
	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		ft_printf("The key %d, data is %s the key value is: %d\n", stack->key,
			stack->data, stack->value);
		stack = stack->next;
	}
	ft_printf("The key %d, data is %s the key value is: %d\n", stack->key,
		stack->data, stack->value);
}

void	ps_printf_both_stacks(t_stack *stack_dst, t_stack *stack_src)
{
	ft_printf("Satack source\n");
	ps_printf_stack(stack_src->head);
	ft_printf("Satack destination\n");
	ps_printf_stack(stack_dst->head);
}

void	ps_printf_solution(t_node_solution *node)
{
	if (!node)
	{
		return ;
	}
	ft_printf("The solution matrix is:\n");
	ft_printf("|\ti\t|\tx\t|\ty\t|\tk\t|\tl\t|\tm\t|\tn\t|"
		"\tSolution\t|\tSolution Value\t|\n");
	while (node)
	{
		ft_printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|"
			"\t   %c      \t|\t      %-7d\t|\n",
			node->key,
			node->x,
			node->y,
			node->k,
			node->l,
			node->m,
			node->n,
			node->sol,
			node->sol_value);
		node = node->next;
	}
}

void	ps_printf_mtx(int **mtx)
{
	int	i;

	i = 0;
	ft_printf("|\tKey\t|\tVal\t|\n");
	while (mtx[i])
	{
		ft_printf("|\t%d\t|\t%d\t|\n", i, mtx[i][1]);
		i++;
	}
}
