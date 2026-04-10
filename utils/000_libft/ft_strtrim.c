/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:57:58 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/20 17:41:17 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Description:
		Allocates memory (using malloc(3)) and returns a copy of ’s1’ with
		characters from ’set’ removed from the beginning and the end.
	Return: 
		The trimmed string. NULL if the allocation fails.
	Parameters:
		s1: The string to be trimmed.
		set: The string containing the set of characters to be removed.
	External Function: 
		malloc
*/

#include "libft.h"

static int	ft_ini_ver(char *ini, char *set)
{
	int	i;

	i = 0;
	while (*set && ft_strchr(set, *ini))
	{
		ini++;
		i++;
	}
	return (i);
}

static int	ft_end_ver(char *end, char *set)
{
	int	i;

	i = ft_strlen(end) - 1;
	while (i > 0 && ft_strchr(set, *(end + i)))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	finish;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup((const char *) ""));
	start = ft_ini_ver((char *) s1, (char *) set);
	finish = (ft_end_ver((char *) s1, (char *) set));
	return (ft_substr(s1, start, (finish - start + 1)));
}
