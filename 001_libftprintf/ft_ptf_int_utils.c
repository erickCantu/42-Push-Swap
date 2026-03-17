/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_int_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:30 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/29 16:59:03 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptf_int_fw(t_ftprintf *data, unsigned int len, char *sval_tmp)
{
	char			*sval_fw_tmp;
	char			*sval_tmp_str;
	unsigned int	fw;

	fw = data->fcs_fw;
	if (*(data->str))
	{
		sval_tmp_str = ft_strjoin(data->str, sval_tmp);
		ft_bzero(data->str, 2);
		sval_fw_tmp = (char *)ft_calloc(fw + 2, sizeof(char));
		ft_memset(sval_fw_tmp, ' ', fw - len);
		ft_memcpy(sval_fw_tmp + fw - len, sval_tmp_str, len + 1);
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

char	*ft_ptf_int_minus(t_ftprintf *data, char *sval)
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

char	*ft_ptf_int_pcs(t_ftprintf *data, unsigned int len, char *sval)
{
	char			*sval_tmp;
	unsigned int	sval_len;

	sval_len = ft_strlen(sval);
	sval_tmp = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memset(sval_tmp, '0', len - sval_len);
	ft_memcpy(sval_tmp + len - sval_len, sval, sval_len);
	if (data->fcs_minus && data->fcs_fw > len)
		sval_tmp = ft_ptf_int_minus(data, sval_tmp);
	else if (data->fcs_fw > len)
		sval_tmp = ft_ptf_int_fw(data, len, sval_tmp);
	free(sval);
	sval = NULL;
	return (sval_tmp);
}

void	ft_ptf_int_sign_case(t_ftprintf *data, int sign, int ival)
{
	if (data->fcs_space && !sign && ival > -2147483648)
	{
		data->str[0] = ' ';
		if (data->fcs_fw)
			data->fcs_fw -= 1;
	}
	if (data->fcs_plus && !sign && ival > -2147483648)
	{
		data->str[0] = '+';
		if (data->fcs_fw)
			data->fcs_fw -= 1;
	}
	if (sign)
	{
		data->str[0] = '-';
		if (data->fcs_fw)
			data->fcs_fw -= 1;
	}
	return ;
}

char	*ft_ptf_int_sval(t_ftprintf *data, char **sval, signed int ival,
		int *sign)
{
	*sign = 0;
	if (ival > -2147483648 && ival < 0)
	{
		ival *= -1;
		*sign = 1;
		*sval = ft_itoa(ival);
	}
	else if (ival == -2147483648)
	{
		*sval = ft_strdup("2147483648");
		*sign = 1;
	}
	else
		*sval = ft_itoa(ival);
	if (!(*sval))
	{
		ft_ptf_clean(data);
		data = NULL;
		return (NULL);
	}
	return (*sval);
}
