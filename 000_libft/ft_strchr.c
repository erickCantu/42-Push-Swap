/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:15:50 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/11/30 12:43:42 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strchr() function returns a pointer to the first occurrence of the 
	character c in the string s.

*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*loc;

	loc = (char *) s;
	while (*loc)
	{
		if (*loc == (unsigned char) c)
			return (loc);
		loc++;
	}
	if (*loc == '\0' && (unsigned char) c == '\0')
		return (loc);
	return (NULL);
}
