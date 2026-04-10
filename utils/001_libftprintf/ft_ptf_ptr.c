/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:46:01 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/29 16:35:04 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ptf_ptr_fw(unsigned int fw, unsigned int len, char *sval_tmp)
{
	char	*sval_fw_tmp;

	sval_fw_tmp = (char *)ft_calloc(fw + 1, sizeof(char));
	ft_memset(sval_fw_tmp, ' ', fw - len);
	ft_memcpy(sval_fw_tmp + fw - len, sval_tmp, len);
	free(sval_tmp);
	sval_tmp = NULL;
	return (sval_fw_tmp);
}

static char	*ft_ptf_ptr_minus(t_ftprintf *data, char *sval)
{
	char			*sval_tmp;
	unsigned int	sval_len;

	sval_len = ft_strlen(sval);
	sval_tmp = (char *)ft_calloc(data->fcs_fw + 1, sizeof(char));
	ft_memcpy(sval_tmp, sval, sval_len);
	ft_memset(sval_tmp + sval_len, ' ', data->fcs_fw - sval_len);
	free(sval);
	sval = NULL;
	return (sval_tmp);
}

unsigned int	ft_ptf_ptr(t_ftprintf *data, size_t uval)
{
	char	*sval;

	if (uval == 0)
		sval = ft_strdup("(nil)");
	else
		sval = ft_ptf_ptohex(uval);
	if (!sval)
		return (ft_ptf_clean(data));
	if (data->fcs_minus && (data->fcs_fw > ((unsigned int)ft_strlen(sval))))
		sval = ft_ptf_ptr_minus(data, sval);
	if (data->fcs_fw > 0 && data->fcs_fw > ((unsigned int)ft_strlen(sval)))
		sval = ft_ptf_ptr_fw(data->fcs_fw, (unsigned int)ft_strlen(sval), sval);
	return (ft_ptf_str_wrt(data, sval));
}
