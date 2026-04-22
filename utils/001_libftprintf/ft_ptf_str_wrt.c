/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_str_wrt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:44:35 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/22 22:00:31 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_ptf_str_wrt(t_ftprintf *data, char *sval)
{
	unsigned int	count;

	count = 0;
	data->str = ft_ptf_str_join(data->str, sval);
	if (!data->str)
	{
		ft_ptf_clean(data);
		data = NULL;
		return (-1);
	}
	free(sval);
	sval = NULL;
	count = count + ft_strlen(data->str);
	ft_putstr_fd(data->str, 1);
	ft_ptf_clean(data);
	data = NULL;
	return (count);
}
