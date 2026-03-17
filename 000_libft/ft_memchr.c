/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:26:30 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/09 13:55:57 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The memchr() function scans the initial n bytes of the memory area 
	pointed to by s for the first instance of c.  Both c and the bytes of
	the memory area pointed to by s are interpreted as unsigned char.

	The memchr() and memrchr() functions return a pointer to the matching 
	byte or NULL if the character does not occur in the  given  memory area.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_cpy;
	unsigned char	*s_cpy;
	size_t			i;

	c_cpy = (unsigned char) c;
	s_cpy = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == c_cpy)
			return ((void *) s_cpy + i);
		i++;
	}
	return (NULL);
}
