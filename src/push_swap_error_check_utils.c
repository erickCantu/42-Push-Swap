/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_check_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:08:44 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/14 11:34:08 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_isduplicate(char *slv[], int size)
{
	int	len;
	int	len_mas_1;

	len = -1;
	while (len++ < size - 1)
	{
		len_mas_1 = len;
		while (len_mas_1++ < size - 1)
		{
			if (ft_atoi(slv[len]) == ft_atoi(slv[len_mas_1]))
				return (0);
		}
	}
	return (1);
}

int	ps_isint(char *nptr)
{
	int			nptr_len;
	long int	num;

	if (!ft_isdigit(nptr[0]) && nptr[0] != '-' && nptr[0] != '+')
		return (0);
	if ((nptr[0] == '-' || nptr[0] == '+') && !ft_isdigit(nptr[1]))
		return (0);
	nptr_len = 1;
	while (nptr[nptr_len])
	{
		if (!ft_isdigit(nptr[nptr_len]))
			return (0);
		nptr_len++;
	}
	num = ps_atoli(nptr);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	else
		return (1);
}

int	ps_initialize_p_argv(t_stack_solutions *sol, int argc, char **argv)
{
	sol->p_argv = ps_checker(argc, argv);
	if (!sol->p_argv)
		return (ps_error("Error", sol->p_argv, 0));
	sol->input_size = ps_dptrlen((const char **)sol->p_argv);
	if (ps_mtx_sol(sol) != 0)
		return (ps_error("\"Fail to create solution matrix\"", sol->p_argv,
				sol->input_size));
	return (0);
}
