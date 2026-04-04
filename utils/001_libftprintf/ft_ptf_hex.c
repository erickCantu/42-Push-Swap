/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:47:41 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/29 16:33:29 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ptf_hex_fw(t_ftprintf *data, unsigned int len, char *sval_tmp)
{
	char			*sval_fw_tmp;
	char			*sval_tmp_str;
	unsigned int	fw;

	fw = data->fcs_fw;
	if (*(data->str))
	{
		sval_tmp_str = ft_strjoin(data->str, sval_tmp);
		ft_bzero(data->str, 3);
		sval_fw_tmp = (char *)ft_calloc(fw + 3, sizeof(char));
		ft_memset(sval_fw_tmp, ' ', fw - len);
		ft_memcpy(sval_fw_tmp + fw - len, sval_tmp_str, len + 2);
		free(sval_tmp_str);
		sval_tmp_str = NULL;
	}
	else
	{
		sval_fw_tmp = (char *)ft_calloc(fw + 1, sizeof(char));
		ft_memset(sval_fw_tmp, ' ', fw - len);
		ft_memcpy(sval_fw_tmp + fw - len, sval_tmp, len);
	}
	free(sval_tmp);
	sval_tmp = NULL;
	return (sval_fw_tmp);
}

static void	ft_ptf_hex_hash(t_ftprintf *data, char hex)
{
	if (data->fcs_fw >= 2)
		data->fcs_fw -= 2;
	data->str[0] = '0';
	if (hex == 'x')
		data->str[1] = 'x';
	else
		data->str[1] = 'X';
	return ;
}

static char	*ft_ptf_hex_zero_pcs(unsigned int len, char *sval)
{
	char			*sval_tmp;
	unsigned int	sval_len;

	sval_len = ft_strlen(sval);
	sval_tmp = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memset(sval_tmp, '0', len - sval_len);
	ft_memcpy(sval_tmp + len - sval_len, sval, sval_len);
	free(sval);
	sval = NULL;
	return (sval_tmp);
}

static char	*ft_ptf_hex_minus(unsigned int len, char *sval)
{
	char			*sval_tmp;
	unsigned int	sval_len;

	sval_len = ft_strlen(sval);
	sval_tmp = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memcpy(sval_tmp, sval, sval_len);
	ft_memset(sval_tmp + sval_len, ' ', len - sval_len);
	free(sval);
	sval = NULL;
	return (sval_tmp);
}

unsigned int	ft_ptf_hex(t_ftprintf *data, unsigned int xval, char hex)
{
	char	*sval;

	data->xval = xval;
	if (data->fcs_pcs && data->fcs_pcs_len == 0 && data->xval == 0)
		sval = ft_strdup("");
	else
		sval = ft_ptf_unitohex(xval);
	if (!sval)
		return (ft_ptf_clean(data));
	if (data->fcs_pcs && (data->fcs_pcs_len > (unsigned int)ft_strlen(sval)))
		sval = ft_ptf_hex_zero_pcs(data->fcs_pcs_len, sval);
	if (data->fcs_hash && xval > 0)
		ft_ptf_hex_hash(data, hex);
	if (data->fcs_zero && (data->fcs_fw > (unsigned int)ft_strlen(sval)))
		sval = ft_ptf_hex_zero_pcs(data->fcs_fw, sval);
	else if (data->fcs_minus && (data->fcs_fw > (unsigned int)ft_strlen(sval)))
		sval = ft_ptf_hex_minus(data->fcs_fw, sval);
	else if (data->fcs_fw > 0 && data->fcs_fw > (unsigned int)ft_strlen(sval))
		sval = ft_ptf_hex_fw(data, (unsigned int)ft_strlen(sval), sval);
	if (hex == 'X')
		sval = ft_str_toupper(sval);
	return (ft_ptf_str_wrt(data, sval));
}
