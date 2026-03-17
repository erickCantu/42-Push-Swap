/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:52:58 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/06 20:23:31 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description:
 *		Iterates through the list ’lst’ and applies the function ’f’ 
 *		to the content of each node.
 *	Return Value:
 *		None
 *	Parameters:
 *		lst: The address of a pointer to a node.
 *		f: The address of the function to apply to each node’s 
 *		content.
 *	External Function:
 *		None
 */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		f(lst -> content);
		lst = lst -> next;
	}
}
