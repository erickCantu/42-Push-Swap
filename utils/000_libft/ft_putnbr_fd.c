/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:38:04 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/20 17:45:25 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	n: The integer to output.
	fd: The file descriptor on which to write.
	Outputs the integer ’n’ to the specified file descriptor.
*/

#include "libft.h"

static int	ft_msize(int n)
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

static void	ft_putnbr_intostr(int n, char *num, int len)
{
	num[(len)] = '\0';
	while (n > 0)
	{
		num[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[11];
	char	sign;
	int		len;
	int		i;

	sign = '\0';
	if (n == -2147483648)
		write(fd, "-2147483648)", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		len = ft_msize(n);
		i = len;
		if (n < 0)
		{
			sign = '-';
			n = -n;
		}
		ft_putnbr_intostr(n, num, len);
		if (sign == '-')
			num[0] = sign;
		write(fd, &(*num), i);
	}
}
