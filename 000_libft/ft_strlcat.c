/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:57:47 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/09 13:26:52 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strlcat() function concatenate strings. Designed to be safer, 
	more consistent, and less error prone replacementstrncat(3).  
	Unlike those functions, strlcat() take the full size of the 
	buffer (not just the length) and guarantee to NUL-terminate the result 
	(as long as there is at least one byte free in dst).  Note that a byte 
	for the NUL should be included in size.  Also note that strlcat() only 
	operate on true “C” strings.
	This means that for	strlcat() both src and dst must be NUL-terminated.
	
	The strlcat() function appends the NUL-terminated string src to the end 
	of dst.  It will append at most size - strlen(dst) - 1 bytes, 
	NUL-terminating the result.

	RETURN VALUES
     The strlcat() function return the total length of the string they tried
	 to create. For strlcat() that means the initial length of dst plus the 
	 length of src. While this may seem somewhat confusing, it was done 
	 to make truncation detection simple.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	i;
	unsigned int	j;

	if (!dst && !src)
		return (0);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *) src);
	i = len_dst + len_src;
	if (size <= len_dst)
		return (len_src + size);
	j = 0;
	while (src[j] && (len_dst + j) < size - 1)
	{
		dst[len_dst + j] = src[j];
		j++;
	}
	dst[len_dst + j] = 0;
	return (i);
}
