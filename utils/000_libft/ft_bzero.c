/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:37:03 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/11/10 17:10:34 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The bzero() function erases the data in the n bytes of the memory starting 
 * at the location pointed to by s, by writing zeros (bytes containing '\0') 
 * to that area.
 * 
 */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = s;
	while (i < n)
	{
		s_cpy[i] = 0;
		i++;
	}
	return (s);
}
