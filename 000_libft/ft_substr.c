/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:07:25 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/10 13:19:31 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates memory (using malloc(3)) and returns a substring from the 
	string ’s’. The substring starts at index ’start’ and has a maximum 
	length of ’len’.

	Return Value: The substring. Otherwise NULL if the allocation fails.

	Parameters: 
		s: The original string from which to create the substring.
		start: The starting index of the substring within ’s’.
		len: The maximum length of the substring.

	External Function:
		malloc
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_cpy;
	size_t	i;
	size_t	s_len;

	if (!s || s[0] == '\0')
		return (ft_strdup(""));
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len - start;
	if (start + len > s_len)
		len = s_len - start;
	i = 0;
	s_cpy = (char *) malloc((len + 1) * sizeof(char));
	if (!s_cpy)
		return (NULL);
	while (i < len)
	{
		s_cpy[i] = ((char *)(s))[start];
		i++;
		start++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}
