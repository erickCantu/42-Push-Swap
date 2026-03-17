/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:43:58 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/27 14:00:17 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptf_str_fw(t_ftprintf *data, char *sval)
{
	char			*str_fw;
	unsigned int	count;
	unsigned int	sval_len;

	count = data->fcs_fw;
	sval_len = ft_strlen(sval);
	str_fw = (char *)ft_calloc(count + 1, sizeof(char));
	ft_memcpy(str_fw + count - sval_len, sval, sval_len);
	ft_memset(str_fw, ' ', count - sval_len);
	ft_putstr_fd(str_fw, 1);
	free(str_fw);
	str_fw = NULL;
	return (count);
}

static int	ft_ptf_str_minus(t_ftprintf *data, char *sval)
{
	char			*str_minus;
	unsigned int	count;
	unsigned int	sval_len;

	count = data->fcs_fw;
	sval_len = ft_strlen(sval);
	str_minus = (char *)ft_calloc(count + 1, sizeof(char));
	ft_memcpy(str_minus, sval, sval_len);
	ft_memset(str_minus + sval_len, ' ', count - sval_len);
	ft_putstr_fd(str_minus, 1);
	free(str_minus);
	str_minus = NULL;
	return (count);
}

static int	ft_ptf_str_pcs(t_ftprintf *data, char *sval)
{
	char			*str_pcs;
	unsigned int	count;

	str_pcs = ft_strdup(sval);
	if (data->fcs_pcs_len <= (unsigned int)ft_strlen(str_pcs))
		str_pcs[data->fcs_pcs_len] = 0;
	count = ft_strlen(str_pcs);
	if (data->fcs_fw > count)
	{
		if (data->fcs_minus)
			count = ft_ptf_str_minus(data, str_pcs);
		else
			count = ft_ptf_str_fw(data, str_pcs);
		free(str_pcs);
		str_pcs = NULL;
		return (count);
	}
	ft_putstr_fd(str_pcs, 1);
	free(str_pcs);
	str_pcs = NULL;
	return (count);
}

static int	ft_ptf_str_case(t_ftprintf *data, char *sval)
{
	unsigned int	count;

	if (data->fcs_pcs && *sval)
		return (ft_ptf_str_pcs(data, sval));
	if (data->fcs_minus && (data->fcs_fw >= (unsigned int)ft_strlen(sval)))
		return (ft_ptf_str_minus(data, sval));
	if (data->fcs_fw > (unsigned int)ft_strlen(sval))
		return (ft_ptf_str_fw(data, sval));
	data->str = ft_ptf_str_join(data->str, sval);
	if (!data->str)
	{
		ft_ptf_clean(data);
		data = NULL;
		return (-1);
	}
	count = ft_strlen(data->str);
	ft_putstr_fd(data->str, 1);
	return (count);
}

unsigned int	ft_ptf_str(t_ftprintf *data, char *sval)
{
	unsigned int	count;

	count = 0;
	if (!sval)
	{
		if (data->fcs_pcs && data->fcs_pcs_len < 6)
			count = ft_ptf_str_case(data, "");
		else
			count = ft_ptf_str_case(data, "(null)");
	}
	else
		count = ft_ptf_str_case(data, sval);
	ft_ptf_clean(data);
	data = NULL;
	return (count);
}
