/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:37:33 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/01 16:57:55 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The memcmp() function compares the first n bytes (each interpreted as 
	unsigned char) of the memory areas s1 and s2.

	The memcmp() function returns an integer less than, equal to, or greater 
	than zero if the first n bytes of s1 is found, respectively, to be less 
	than, to match, or be greater than the first n bytes of s2.

    For a nonzero return value, the sign is determined by the sign of the 
	difference between the first pair of  bytes  (interpreted  as  unsigned 
	char) that differ in s1 and s2.
    
	If n is zero, the return value is zero.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	if (n == 0)
		return (0);
	i = 0;
	s1_cpy = (unsigned char *) s1;
	s2_cpy = (unsigned char *) s2;
	while (n > 0)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return (s1_cpy[i] - s2_cpy[i]);
		else
		{
			i++;
			n--;
		}
	}
	return (0);
}
