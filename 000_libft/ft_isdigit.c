/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:41:00 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/08 19:02:30 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* This function checks if an unsigned char is a digit.
* checks for a digit (0 through 9).
*
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
