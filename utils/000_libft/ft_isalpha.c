/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:41:00 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/08 19:02:32 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* checks for an alphabetic character; in the standard "C" locale, it is 
* equivalent to (isupper(c) ||  islower(c)).   In  some  locales, there 
* may be additional characters for which isalpha() is true—letters which 
* are neither uppercase nor lowercase.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
