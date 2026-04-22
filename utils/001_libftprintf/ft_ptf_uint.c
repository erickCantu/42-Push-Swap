/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:00 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/29 16:35:23 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ptf_uint_fw(unsigned int fw, unsigned int len, char *sval_tmp)
{
	char	*sval_fw_tmp;

	sval_fw_tmp = (char *)ft_calloc(fw + 1, sizeof(char));
	ft_memset(sval_fw_tmp, ' ', fw - len);
	ft_memcpy(sval_fw_tmp + fw - len, sval_tmp, len);
	free(sval_tmp);
	sval_tmp = NULL;
	return (sval_fw_tmp);
}

static char	*ft_ptf_uint_minus(t_ftprintf *data, char *sval)
{
	char			*sval_tmp;
	unsigned int	sval_len;
	unsigned int	len;

	len = data->fcs_fw;
	sval_len = ft_strlen(sval);
	sval_tmp = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memcpy(sval_tmp, sval, sval_len);
	ft_memset(sval_tmp + sval_len, ' ', len - sval_len);
	free(sval);
	sval = NULL;
	return (sval_tmp);
}

static char	*ft_ptf_uint_pcs(t_ftprintf *data, unsigned int len, char *sval)
{
	char			*sval_tmp;
	unsigned int	sval_len;

	sval_len = ft_strlen(sval);
	sval_tmp = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memset(sval_tmp, '0', len - sval_len);
	ft_memcpy(sval_tmp + len - sval_len, sval, sval_len);
	if (data->fcs_minus && data->fcs_fw > len)
		sval_tmp = ft_ptf_uint_minus(data, sval_tmp);
	else if (data->fcs_fw > len)
		sval_tmp = ft_ptf_uint_fw(data->fcs_fw, len, sval_tmp);
	free(sval);
	sval = NULL;
	return (sval_tmp);
}

unsigned int	ft_ptf_uint(t_ftprintf *data, unsigned int uval)
{
	char			*sval;
	unsigned int	sval_len;

	data->uval = uval;
	if (data->fcs_pcs && data->fcs_pcs_len == 0 && data->uval == 0)
		sval = ft_strdup("");
	else
		sval = ft_ptf_uitoa(uval);
	if (!sval)
		return (ft_ptf_clean(data));
	sval_len = ft_strlen(sval);
	if (data->fcs_pcs && (data->fcs_pcs_len > sval_len))
		sval = ft_ptf_uint_pcs(data, data->fcs_pcs_len, sval);
	else if (data->fcs_zero && (data->fcs_fw > sval_len))
		sval = ft_ptf_uint_pcs(data, data->fcs_fw, sval);
	else if (data->fcs_minus && (data->fcs_fw > sval_len))
		sval = ft_ptf_uint_minus(data, sval);
	else if (data->fcs_fw > 0 && data->fcs_fw > sval_len)
		sval = ft_ptf_uint_fw(data->fcs_fw, sval_len, sval);
	return (ft_ptf_str_wrt(data, sval));
}
