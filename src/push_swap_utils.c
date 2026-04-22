/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:19:36 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 12:33:59 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_dptrlen(const char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ps_initialize_avg_std(t_stack *stack_a, t_stack *stack_b, int **mtx)
{
	if (stack_a->stack_size == 1)
		return ;
	stack_a->avg = ft_mean(mtx, stack_a->stack_size);
	stack_a->stdev = ft_pseudo_stdev_s(stack_a->stack_size, mtx, stack_a->avg);
	stack_b->avg = stack_a->avg;
	stack_b->stdev = stack_b->stdev;
}

int	ft_mean(int **mtx, size_t mtx_len)
{
	int		counter;
	size_t	sum;

	counter = mtx_len;
	sum = 0;
	while (counter-- > 0)
	{
		sum += mtx[counter][1];
	}
	return (sum / (mtx_len));
}

long long int	ft_pseudo_sqrt(long long int nb)
{
	long long int	i;
	long long int	j;
	long long int	k;

	if (nb <= 0)
		return (0);
	i = 1;
	j = 0;
	k = nb;
	while (nb > 0)
	{
		nb = nb - (1 * i);
		i = i + 2;
		j++;
	}
	if (k == (j * j))
		return (j);
	return (j);
}

int	ft_pseudo_stdev_s(int mtx_len, int **mtx, int average)
{
	int				counter;
	long long int	x_diff;
	long long int	stdev_s;
	long long int	sum_sq;

	counter = mtx_len;
	x_diff = 0;
	sum_sq = 0;
	while (counter-- > 0)
	{
		x_diff = mtx[counter][1] - average;
		sum_sq += (x_diff * x_diff);
	}
	stdev_s = ft_pseudo_sqrt(sum_sq / (mtx_len - 1));
	return (stdev_s);
}
