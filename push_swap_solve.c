/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:55:48 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:46:18 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ini_sort_1_node(t_stack *stack_dst, t_stack *stack_src)
{
	int	x;
	int	y;

	ps_ini_sort_1_node_x_y_calc(stack_src, &x, &y, -5);
	while (x > 0 && y > 0)
	{
		if (x < y)
		{
			while (x > 0)
			{
				ps_r(stack_src, 'a');
				x--;
			}
		}
		else
		{
			while (y > 0)
			{
				ps_rr(stack_src, 'a');
				y--;
			}
		}
	}
	ps_p(stack_dst, stack_src, 'b');
}

void	ps_ini_sort_1_node_x_y_calc(t_stack *stack, int *x, int *y, int j)
{
	t_node	*tmp_h;
	t_node	*tmp_t;

	while (j)
	{
		tmp_h = stack->head;
		tmp_t = stack->tail;
		*x = 0;
		*y = 1;
		while (tmp_h && tmp_h->value > stack->avg + ((stack->stdev / 3) * j))
		{
			tmp_h = tmp_h->next;
			(*x)++;
		}
		while (tmp_t && tmp_t->value > stack->avg + ((stack->stdev / 3) * j))
		{
			tmp_t = tmp_t->prev;
			(*y)++;
		}
		if (!tmp_h || !tmp_t || (*x > 70 && *y > 70))
			j++;
		else
			j = 0;
	}
}

void	ps_initialize_ranking(t_node *head, t_stack_solutions sol)
{
	int	i;

	while (head)
	{
		i = 0;
		while (i < sol.input_size)
		{
			if (sol.mtx[i][1] == head->value)
			{
				head->value = i;
				break ;
			}
			else
				i++;
		}
		head = head->next;
	}
}

void	ps_sol_ini(t_stack *stack_a, t_stack_solutions *sol, t_counters *count)
{
	sol->c_d = (stack_a->avg + ((stack_a->stdev / 3) * sol->cluster_counter));
	if (stack_a->head->next && stack_a->head->value > stack_a->head->next->value
		&& (stack_a->head->value < sol->c_d))
		ps_s(stack_a, 'a');
	ps_initialize_counters(count);
	sol->run = 0;
}
