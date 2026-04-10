/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_unitohex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:59:34 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/29 16:32:53 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ptf_itohex_str_switch(char *str_hex, char *str_tmp, int i)
{
	int	j;

	j = 0;
	while (i > 0)
	{
		*(str_hex + j) = *(str_tmp + i - 1);
		i--;
		j++;
	}
}

static void	ft_ptf_itohex_conv(unsigned int n, char *str_hex, char *str_tmp)
{
	int	i;
	int	res;

	i = 0;
	if (n != 0)
	{
		while (n > 0)
		{
			res = n % 16;
			n /= 16;
			if (res < 10)
				*(str_tmp + i) = res + 48;
			else
				*(str_tmp + i) = res + 87;
			i++;
		}
		ft_ptf_itohex_str_switch(str_hex, str_tmp, i);
	}
	else
		*str_hex = 0 + 48;
	free(str_tmp);
	str_tmp = NULL;
}

char	*ft_ptf_unitohex(unsigned int n)
{
	char	*str_tmp;
	char	*str_hex;

	str_tmp = (char *)ft_calloc(9, sizeof(unsigned int));
	str_hex = (char *)ft_calloc(9, sizeof(unsigned int));
	if (!str_tmp || !str_hex)
		return (NULL);
	ft_ptf_itohex_conv(n, str_hex, str_tmp);
	return (str_hex);
}

// int main(void)
// {
//     char    *str_hex;
//     unsigned int     n;
//
//     n = 4294967295;
// 	str_hex = ft_unitohex(n);
//     printf("f:%s\n",str_hex);
//     printf("x:%x\n", n);
//     printf("u:%u\n", n);
//     printf("i:%i\n", n);
//     printf("d:%d\n", n);
//
// 	free(str_hex);
//     return (0);
// }