/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_advance_rules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:31:39 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/13 14:44:30 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rab(t_stack *a, t_stack *b)
{
	ps_r(a, 0);
	ps_r(b, 0);
	ft_printf("rr\n");
}

void	ps_rrab(t_stack *a, t_stack *b)
{
	ps_rr(a, 0);
	ps_rr(b, 0);
	ft_printf("rrr\n");
}
