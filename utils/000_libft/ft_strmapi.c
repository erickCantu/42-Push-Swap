/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:59:32 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/04 16:42:24 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Applies the function f to each character of the string s, passing 
	its index as the first argument and the character itself as the second. 
	A new string is created (using malloc(3)) to store the results from 
	the successive applications of f.

	s: The string to iterate over.
	f: The function to apply to each character.

	Return Value:
		The string created from the successive applications of ’f’.
		Returns NULL if the allocation fails.

	External Fuction: 
		malloc
	
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	ret = (char *) malloc ((len + 1) * sizeof (char));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
