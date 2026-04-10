/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_uitoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:14:41 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/29 16:28:25 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This is the same logic as ft_itoa.c. Except that accepts an unsigned
	integer

	The string representing the unsigned integer. NULL if the allocation fails.

	Allocates memory (using malloc(3)) and returns a string representing the
	unsigned integer received as an argument. Negative numbers must be handled.


*/

#include "ft_printf.h"

int	ft_ptf_uitoa_msize(unsigned int n)
{
	int				i;
	unsigned int	n_cpy;

	n_cpy = n;
	i = 0;
	if (n == 0)
		return (1);
	while (n_cpy > 0)
	{
		n_cpy /= 10;
		i++;
	}
	return (i);
}

char	*ft_ptf_uintos(unsigned int n, char *s_num, int len_n)
{
	int		i;
	char	sign;

	i = len_n;
	sign = '\0';
	while (n > 0)
	{
		*(s_num + (len_n - 1)) = n % 10 + 48;
		n /= 10;
		len_n--;
	}
	if (sign == '-')
	{
		*(s_num) = sign;
	}
	*(s_num + i) = '\0';
	return (s_num);
}

char	*ft_ptf_uitoa(unsigned int n)
{
	char	*s_num;
	int		len_n;

	len_n = (ft_ptf_uitoa_msize(n));
	s_num = (char *)ft_calloc((len_n + 1), sizeof(char));
	if (!s_num)
		return (NULL);
	if (n == 0)
	{
		*(s_num) = '0';
		*(s_num + 1) = '\0';
		return (s_num);
	}
	s_num = ft_ptf_uintos(n, s_num, len_n);
	return (s_num);
}

// int		main(void)
// {
// 	char	*str;
//
// 	str = ft_uitoa(4294967292);
// 	printf("%s", str);
// 	return(0);
// }