/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:02:06 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/09 13:43:26 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The  strdup()  function  returns  a pointer to a new string which is a 
	duplicate of the string s.  Memory for the new string is obtained with 
	malloc(3), and can be freed with free(3).

	On success, the strdup() function returns a pointer to the dupicated 
	string.  It returns NULL if  insufficient  memory  was  available,
	with errno set to indicate the cause of the error.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len_str;
	int		i;

	len_str = 0;
	len_str = ft_strlen(s);
	if (!len_str)
		return (ft_calloc(1, sizeof(char)));
	dup = malloc((len_str + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len_str)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
