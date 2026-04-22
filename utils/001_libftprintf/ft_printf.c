/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:10:40 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/02/03 12:55:18 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		count;
	char	*ptr;
	va_list	ap;

	count = 0;
	va_start(ap, fmt);
	ptr = (char *)fmt;
	if (ft_ptf_printf_check(ptr))
		return (-1);
	while (*ptr)
	{
		count += ft_ptf_flags_case(&ptr, ap);
		if (*ptr)
			ptr++;
	}
	va_end(ap);
	return (count);
}
