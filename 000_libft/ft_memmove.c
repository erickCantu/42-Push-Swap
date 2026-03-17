/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:12:32 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/09 11:42:21 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The  memmove()  function  copies n bytes from memory area src to memory 
 * area dest.  The memory areas may overlap: copying takes place as 
 * though the bytes in src are first copied into a temporary array that does 
 * not overlap src or dest, and the bytes are  then  copied  from the 
 * temporary array to dest. 
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if (!dest && !src)
		return (dest);
	i = 0;
	src_cpy = (unsigned char *) src;
	dest_cpy = (unsigned char *) dest;
	if (dest_cpy > src_cpy)
	{
		while (n-- > 0)
			dest_cpy[n] = src_cpy[n];
	}
	else
	{
		while (i < n)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	}
	return (dest);
}
