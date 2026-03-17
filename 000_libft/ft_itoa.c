/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:45:54 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/28 20:27:12 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Description:
	Allocates memory (using malloc(3)) and returns a string representing the
	integer received as an argument. Negative numbers must be handled.

	Return Value:
	The string representing the integer. NULL if the allocation fails.

	Parameters:
		n: The integer to convert.

	External Function:
		malloc
*/

#include "libft.h"

static int	ft_itoa_msize(int n)
{
	int	i;
	int	n_cpy;

	n_cpy = n;
	i = 0;
	if (n == 0)
		return (1);
	if (n_cpy < 0)
	{
		n_cpy = -n_cpy;
		i++;
	}
	while (n_cpy > 0)
	{
		n_cpy /= 10;
		i++;
	}
	return (i);
}

static char	*ft_intos(int n, char *s_num, int len_n)
{
	int		i;
	char	sign;

	i = len_n;
	sign = '\0';
	if (n < 0)
	{
		sign = '-';
		n = -n;
	}
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

static char	*ft_itoa_cero(char *s_num)
{
	*(s_num) = '0';
	*(s_num + 1) = '\0';
	return (s_num);
}

char	*ft_itoa(int n)
{
	char	*s_num;
	int		len_n;

	if (n == -2147483648)
	{
		s_num = (char *)ft_calloc(12, sizeof(char));
		if (!s_num)
			return (NULL);
		ft_strlcpy(s_num, "-2147483648", 12);
		return (s_num);
	}
	len_n = (ft_itoa_msize(n));
	s_num = (char *)ft_calloc((len_n + 1), sizeof(char));
	if (!s_num)
		return (NULL);
	if (n == 0)
		return (ft_itoa_cero(s_num));
	s_num = ft_intos(n, s_num, len_n);
	return (s_num);
}
