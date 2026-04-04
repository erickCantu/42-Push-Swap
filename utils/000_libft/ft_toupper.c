/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:00 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/10 12:41:26 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* These functions convert lowercase letters to uppercase, and vice versa.
   If  c  is  a  lowercase letter, toupper() returns its uppercase equivalent, 
   if an uppercase representation exists in the current locale.Otherwise, it 
   returns c. 
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if ((unsigned char) c >= 'a' && (unsigned char) c <= 'z')
		return (c - (97 - 65));
	return (c);
}
