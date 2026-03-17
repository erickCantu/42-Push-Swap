/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:41:00 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/08 19:02:37 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* checks for an alphanumeric character; it is equivalent to 
* (isalpha(c) || isdigit(c)).
*
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
