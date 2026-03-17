/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:41:00 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/08 20:03:36 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* checks whether c is a 7-bit unsigned char value that fits into the 
* ASCII character set.
*
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
