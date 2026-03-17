/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:09:21 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/20 17:41:01 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strnstr() function locates the first occurrence of the null-terminated 
	string little in the string big, where not more than len characters are 
	searched.  Characters that appear after a ‘\0’ character are not searched.
	Since the strnstr() function is a FreeBSD specific API, it should only be 
	used when portability is not a concern.

	If little is an empty string, big is returned; if little occurs nowhere in 
	big, NULL is returned; otherwise a pointer to the first character of the 
	first occurrence of little is returned.
*/

#include "libft.h"

static int	ft_strnstr_inside(char *str_in, char *to_find_in, size_t len)
{
	while (*str_in && *to_find_in && len > 0)
	{
		if (*str_in != *to_find_in)
			return (0);
		else
		{
			str_in++;
			to_find_in++;
			len--;
		}
		if (!*str_in)
			if (*to_find_in)
				return (0);
	}
	if (*to_find_in != '\0')
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_cpy;
	char	*little_cpy;

	big_cpy = (char *) big;
	little_cpy = (char *) little;
	if (big == NULL && little == NULL)
		return (NULL);
	if (!*little)
		return (big_cpy);
	while (*big_cpy && len > 0)
	{
		if (*big_cpy != *little_cpy)
		{
			big_cpy++;
			len--;
		}
		else
		{
			if (ft_strnstr_inside(big_cpy, little_cpy, len))
				return (big_cpy++);
			big_cpy++;
			len--;
		}
	}
	return (NULL);
}
