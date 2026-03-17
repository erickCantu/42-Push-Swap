/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:15:50 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/04 23:25:30 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strrchr() function returns a pointer to the last occurrence of the 
	character c in the string s.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*loc;

	i = 0;
	while (s[i])
		i++;
	loc = (char *) s;
	loc += i;
	while (i >= 0)
	{
		if (*loc == (unsigned char) c)
			return (loc);
		else
		{
			loc--;
			i--;
		}
	}
	return (NULL);
}
