/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:46:27 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/20 17:40:50 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strcmp() function compares the two strings s1 and s2.  
	The locale is not taken into account (for a locale-aware comparison, 
	see strcoll(3)).  The comparison is done using unsigned characters.

       strcmp() returns an integer indicating the result of the comparison, 
	   as follows:

       • 0, if the s1 and s2 are equal;

       • a negative value if s1 is less than s2;

       • a positive value if s1 is greater than s2.

       The strncmp() function is similar, except it compares only the first 
	   (at most) n bytes of s1 and s2.

*/

#include "libft.h"

static int	ft_strncmp_op(unsigned char s1, unsigned char s2)
{
	if (s1 - s2 > 0)
		return (1);
	else if (s1 - s2 < 0)
		return (-1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1[i] == '\0' || s2[i] == '\0')
		return (ft_strncmp_op(s1[i], s2[i]));
	while (s1[i] && s2[i] && n > 1)
	{
		if (s1[i] != s2[i])
			return (ft_strncmp_op(s1[i], s2[i]));
		else
		{
			i++;
			n--;
		}
	}
	return (ft_strncmp_op(s1[i], s2[i]));
}
