/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:12:32 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/05 12:02:20 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 * The  memcpy()  function  copies n bytes from memory area src to 
 * memory area dest.  The memory areas must not overlap.  
 * Use memmove(3) if  the memory areas do overlap.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if (!dest && !src)
		return (NULL);
	i = 0;
	src_cpy = (unsigned char *)src;
	dest_cpy = (unsigned char *)dest;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
