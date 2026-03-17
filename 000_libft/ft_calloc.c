/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:12:40 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/04 17:01:35 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The calloc() function allocates memory for an array of nmemb elements of 
	size bytes each and returns a pointer to the allocated  memory.
	The  memory  is set to zero.  If nmemb or size is 0, then calloc() returns
	either NULL, or a unique pointer value that can later be successfully 
	passed to free().  If the multiplication of nmemb and size would result 
	in integer overflow, then calloc() returns  an  error.
	By  contrast,  an  integer  overflow  would not be detected in the 
	following call to malloc(), with the result that an incorrectly sized
	block of memory would be allocated:

           malloc(nmemb * size);


	The malloc() and calloc() functions return a pointer to the allocated 
	memory, which is suitably aligned for any built-in type.   
	On  error,  these  functions  return NULL.  NULL may also be returned 
	by a successful call to malloc() with a size of zero, or by a successful
	call to calloc() with nmemb or size equal to zero.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > 4294967295 || (nmemb * size) > 4294967295)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		ptr = (void *) malloc(0);
		if (!ptr)
			return (NULL);
		ft_memset(ptr, 0, 0);
		return (ptr);
	}
	ptr = (void *) malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
