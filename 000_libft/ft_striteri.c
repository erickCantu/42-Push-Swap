/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:01:28 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/04 16:43:37 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Applies the function ’f’ to each character of the string passed as 
	argument, passing its index as the first argument. 
	Each character is passed by address to ’f’ so it can be modified 
	if necessary.
	
	s: The string to iterate over.
	f: The function to apply to each character.
	
	Return Value: NONE
	External Function: None
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
