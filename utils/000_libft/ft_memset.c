/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:41:00 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/11/10 16:26:55 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* The memset() function fills the first n bytes of the memory area pointed 
* to by s with the constant byte c.
*
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s_cpy;
	unsigned char	c_cpy;

	i = 0;
	s_cpy = s;
	c_cpy = c;
	while (i < n)
	{
		s_cpy[i] = c_cpy;
		i++;
	}
	return (s);
}
