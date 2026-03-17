/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:48:58 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/02/07 19:41:38 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates memory (using malloc(3)) and returns a new string, which is
	the result of concatenating ’s1’ and ’s2’.

	Return Value: The substring. Otherwise NULL if the allocation fails.

	Parameters:
		s1: The prefix string.
		s2: The suffix string.

	External function: 
		malloc
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_join_s2;
	double	len_s1;
	double	len_s2;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	len_s1 = (double)(ft_strlen((char *)s1));
	len_s2 = (double)(ft_strlen((char *)s2));
	if (len_s1 > 4294967295 || len_s2 > 4294967295 || (len_s1
			+ len_s2) > 4294967295)
		return (NULL);
	s1_join_s2 = (char *)ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!s1_join_s2)
		return (NULL);
	ft_memcpy(s1_join_s2, s1, len_s1);
	ft_memcpy((s1_join_s2 + ((int)len_s1)), s2, len_s2);
	s1_join_s2[(int)(len_s1 + len_s2)] = '\0';
	return (s1_join_s2);
}
