/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:50:12 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/02/03 12:50:18 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_ptf_case(char **ptr, t_ftprintf *data, va_list ap)
{
	unsigned int	count;

	count = 0;
	if (*(*ptr) == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
		ft_ptf_clean(data);
		data = NULL;
	}
	else if (*(*ptr) == 'c')
		count += ft_ptf_char(data, va_arg(ap, unsigned int));
	else if (*(*ptr) == 's')
		count += ft_ptf_str(data, va_arg(ap, char *));
	else if (*(*ptr) == 'd' || *(*ptr) == 'i')
		count += ft_ptf_int(data, va_arg(ap, signed int));
	else if (*(*ptr) == 'u')
		count += ft_ptf_uint(data, va_arg(ap, unsigned int));
	else if (*(*ptr) == 'p')
		count += ft_ptf_ptr(data, va_arg(ap, size_t));
	else if (*(*ptr) == 'x')
		count += ft_ptf_hex(data, va_arg(ap, unsigned int), 'x');
	else if (*(*ptr) == 'X')
		count += ft_ptf_hex(data, va_arg(ap, unsigned int), 'X');
	return (count);
}

void	ft_ptf_check_flags(t_ftprintf *data, char **ptr)
{
	if (*(*ptr) == '-')
	{
		data->fcs_minus = 1;
		(*ptr)++;
	}
	if (*(*ptr) == '+')
	{
		data->fcs_plus = 1;
		(*ptr)++;
	}
	if (*(*ptr) == ' ')
	{
		data->fcs_space = 1;
		(*ptr)++;
	}
	if (*(*ptr) == '#')
	{
		data->fcs_hash = 1;
		(*ptr)++;
	}
}

void	ft_ptf_check_precision(t_ftprintf *data, char **ptr)
{
	char	num_int[4096];
	int		i;

	if (*(*ptr) == '.')
	{
		data->fcs_pcs = 1;
		data->fcs_zero = 0;
		(*ptr)++;
		if (ft_isdigit(*(*ptr)))
		{
			i = 0;
			while (ft_isdigit(*(*ptr)))
			{
				num_int[i] = *(*ptr);
				i++;
				(*ptr)++;
			}
			num_int[i] = 0;
			data->fcs_pcs_len = ft_atoi(num_int);
		}
	}
}

void	ft_ptf_check_zero(t_ftprintf *data, char **ptr)
{
	char	num_int[4096];
	int		i;

	if (*(*ptr) == '0')
	{
		if (!data->fcs_minus)
			data->fcs_zero = 1;
		(*ptr)++;
	}
	if (ft_isdigit(*(*ptr)))
	{
		i = 0;
		while (ft_isdigit(*(*ptr)))
		{
			num_int[i] = *(*ptr);
			i++;
			(*ptr)++;
		}
		num_int[i] = 0;
		data->fcs_fw = ft_atoi(num_int);
	}
}

unsigned int	ft_ptf_flags_case(char **ptr, va_list ap)
{
	unsigned int	count;
	t_ftprintf		*data;

	data = ft_ptf_lstnew();
	count = 0;
	if (*(*ptr) != '%')
		count += ft_ptf_char(data, *(*ptr));
	else
	{
		(*ptr)++;
		while (*(*ptr) && !(*(*ptr) == 'c' || *(*ptr) == 's' || *(*ptr) == 'p'
				|| *(*ptr) == 'd' || *(*ptr) == 'i' || *(*ptr) == 'u'
				|| *(*ptr) == 'x' || *(*ptr) == 'X' || *(*ptr) == '%'))
		{
			ft_ptf_check_flags(data, ptr);
			ft_ptf_check_zero(data, ptr);
			ft_ptf_check_precision(data, ptr);
		}
		if (*(*ptr))
			count += ft_ptf_case(ptr, data, ap);
	}
	return (count);
}
