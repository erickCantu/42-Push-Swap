/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:58:41 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/10 12:41:25 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* These functions convert lowercase letters to uppercase, and vice versa.
   If c is an uppercase letter, tolower() returns its lowercase equivalent, 
   if a lowercase representation exists  in  the  current  locale. Otherwise, 
   it returns c. 
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if ((unsigned char) c >= 'A' && (unsigned char) c <= 'Z')
		return (c + (97 - 65));
	return (c);
}
