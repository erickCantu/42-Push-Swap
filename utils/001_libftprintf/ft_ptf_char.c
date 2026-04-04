/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:43:11 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/27 13:56:51 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_ptf_char_fw(t_ftprintf *data, unsigned char cval)
{
	unsigned int	fw;

	fw = data->fcs_fw;
	while (data->fcs_fw > 1)
	{
		ft_putchar_fd(' ', 1);
		data->fcs_fw--;
	}
	ft_putchar_fd(cval, 1);
	ft_ptf_clean(data);
	data = NULL;
	return (fw);
}

unsigned int	ft_ptf_char_minus(t_ftprintf *data, unsigned char cval)
{
	unsigned int	fw;

	fw = data->fcs_fw;
	ft_putchar_fd(cval, 1);
	data->fcs_fw--;
	while (data->fcs_fw > 0)
	{
		ft_putchar_fd(' ', 1);
		data->fcs_fw--;
	}
	ft_ptf_clean(data);
	data = NULL;
	return (fw);
}

unsigned int	ft_ptf_char(t_ftprintf *data, unsigned char cval)
{
	if (data->fcs_minus && data->fcs_fw > 0)
		return (ft_ptf_char_minus(data, cval));
	if (data->fcs_fw > 0)
		return (ft_ptf_char_fw(data, cval));
	ft_putchar_fd(cval, 1);
	ft_ptf_clean(data);
	data = NULL;
	return (1);
}
