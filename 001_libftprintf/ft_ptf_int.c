/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:30 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/29 17:04:31 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_ptf_int(t_ftprintf *data, int ival)
{
	char			*sval;
	unsigned int	sval_len;
	int				sign;

	sign = 0;
	data->ival = ival;
	if (data->fcs_pcs && data->fcs_pcs_len == 0 && data->ival == 0)
		sval = ft_strdup("");
	else
		sval = ft_ptf_int_sval(data, &sval, ival, &sign);
	if (!sval)
		return (ft_ptf_clean(data));
	sval_len = ft_strlen(sval);
	ft_ptf_int_sign_case(data, sign, ival);
	if (data->fcs_pcs && (data->fcs_pcs_len > sval_len))
		sval = ft_ptf_int_pcs(data, data->fcs_pcs_len, sval);
	else if (data->fcs_zero && (data->fcs_fw > sval_len))
		sval = ft_ptf_int_pcs(data, data->fcs_fw, sval);
	else if (data->fcs_minus && (data->fcs_fw > sval_len))
		sval = ft_ptf_int_minus(data, sval);
	else if ((data->fcs_fw > 0) && (data->fcs_fw > sval_len))
		sval = ft_ptf_int_fw(data, sval_len, sval);
	return (ft_ptf_str_wrt(data, sval));
}
