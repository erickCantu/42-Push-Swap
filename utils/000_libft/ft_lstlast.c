/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:45:45 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/06 20:22:15 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description:
 *		Returns the last node of the list.
 *	Return Value:
 *		Last node of the list.
 *	Parameters:
 *		lst: The beginning of the list.
 *	External Function:
 *		None
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

// int main ()
// {
//     t_list *node1;
//     t_list *node2;
//     t_list *node3;
//     t_list *node4;
//
//
//     node1 = ft_lstnew("This is node 1");
//     node2 = ft_lstnew("This is node 2");
//     node3 = ft_lstnew("This is node 3");
//
//     node1 -> next = node2;
//     node2 -> next = node3;
//
//     node4 = ft_lstlast(node1);
//
//     return (0);
//
// }
