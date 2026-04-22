/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:40:07 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/06 20:16:40 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description:
 *		Adds the node ’new’ at the beginning of the list.
 *	Return Value:
 *		None.
 *	Parameters:
 *		lst: The address of a pointer to the first node of a list.
		new: The address of a pointer to the node to be added.
 *	External Function:
 *		None
 */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

// int main ()
// {
//     t_list *node1;
//     t_list *node2;
//     t_list *node3;
//     t_list *node4;
// 		t_list **node;
//
// 		node = (t_list **) malloc (3 * sizeof(t_list));
//     node1 = ft_lstnew("This is node 1");
//     node2 = ft_lstnew("This is node 2");
//     node3 = ft_lstnew("This is node 3");
// 	node4 = ft_lstnew("This is node 4");
// 	node[1] = node1;
//     node1 -> next = node2;
//     node2 -> next = node3;

//     ft_lstadd_front(node1, node4);

//     return (0);

// }
