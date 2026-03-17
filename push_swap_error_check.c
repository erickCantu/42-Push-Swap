/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:19:36 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/10 20:51:38 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_error(char *str, char **ptr, size_t ptr_len)
{
	if (ptr)
		ps_clean((void **)ptr, ptr_len);
	ft_printf("%s\n", str);
	return (-1);
}

long int	ps_atoli(const char *nptr)
{
	int			len;
	long int	num;
	long int	sign;

	len = 0;
	num = 0;
	sign = 1;
	while ((nptr[len] >= 9 && nptr[len] <= 13) || nptr[len] == 32)
		len++;
	if (nptr[len] == '-' || nptr[len] == '+')
	{
		if (nptr[len] == '-')
			sign = -1;
		len++;
	}
	while (nptr[len] >= '0' && nptr[len] <= '9')
	{
		num = (num * 10) + (nptr[len] - 48);
		len++;
	}
	num *= sign;
	return (num);
}

void	ps_free_p_argv(int argc, char **p_argv)
{
	size_t	len;

	len = 0;
	if (argc == 2)
	{
		while (p_argv[len])
		{
			ps_free((void **)&(p_argv[len]));
			len++;
		}
	}
	ps_free((void **)&p_argv);
}

char	**ps_checker_arg(char **p_argv)
{
	int	size;
	int	len;

	size = (int)ps_dptrlen((const char **)p_argv);
	len = 0;
	while (len < size)
	{
		if (!ps_isint(p_argv[len]))
			return (NULL);
		len++;
	}
	if (!ps_isduplicate(p_argv, size))
		return (NULL);
	return (p_argv);
}

char	**ps_checker(int argc, char *argv[])
{
	char	**p_argv;
	int		len;

	if (argc == 2)
	{
		p_argv = ft_split(argv[1], ' ');
		if (!p_argv || !*p_argv)
			return (NULL);
	}
	else
	{
		len = 0;
		p_argv = (char **)ft_calloc(argc, sizeof(char *));
		if (!p_argv)
			return (NULL);
		while (argv[len])
		{
			p_argv[len] = argv[len + 1];
			len++;
		}
	}
	if (!ps_checker_arg(p_argv))
		return (ps_free_p_argv(argc, p_argv), NULL);
	return (p_argv);
}
