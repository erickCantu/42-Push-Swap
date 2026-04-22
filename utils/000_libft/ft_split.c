/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:05:04 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/08 17:47:06 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Description:
		Allocates memory (using malloc(3)) and returns an array of strings
		obtained by splitting ’s’ using the character ’c’ as a delimiter.
		The array must end with a NULL pointer.

	Return value:
		The array of new strings resulting from the split. NULL if the
		allocation fails.

	Parameters:
		s: The string to be split.
		c: The delimiter character.

	External Function:
		malloc, free
*/

#include "libft.h"

static int	ft_split_count(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s == c)
	{
		s++;
	}
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		i++;
	}
	return (i);
}

static void	ft_split_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

static char	*ft_split_cpy_str(const char *s_cpy, int i)
{
	int		k;
	char	*str;

	k = 0;
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (k < i)
	{
		str[k] = *s_cpy;
		k++;
		s_cpy++;
	}
	return (str);
}

static int	ft_split_save_str(int str_cnt, char **arr_str, const char *s_cpy,
		char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < str_cnt)
	{
		while (*(s_cpy) == c && *s_cpy)
			s_cpy++;
		while (*(s_cpy + i) && *(s_cpy + i) != c)
			i++;
		arr_str[j] = ft_split_cpy_str(s_cpy, i);
		if (!arr_str[j])
		{
			ft_split_free_arr(arr_str);
			return (0);
		}
		if (j < (str_cnt + 1))
			s_cpy += (i + 1);
		i = 0;
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_str;
	int		err_check;
	int		len_s;

	if (!s)
		return (NULL);
	len_s = ft_split_count(s, c);
	arr_str = (char **)ft_calloc((len_s + 1), sizeof(char *));
	if (!arr_str)
		return (NULL);
	err_check = 1;
	err_check = ft_split_save_str(len_s, arr_str, s, c);
	if (err_check == 0)
		return (NULL);
	return (arr_str);
}
