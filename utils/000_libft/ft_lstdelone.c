/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:49:36 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/07 17:25:09 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description:
 *		Takes a node as parameter and frees its content using the 
 *		function ’del’. Free the node itself but does NOT free the 
 *		next node.
 *	Return Value:
 *		None
 *	Parameters:
 *		lst: The node to free.
 *		del: The address of the function used to delete the content.
 *	External Function:
 *		free
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	lst -> content = NULL;
	free(lst);
	lst = NULL;
}

// int main ()
// {
//     t_list *node1;
//     char    *str;
//
//     str = strdup("this is node 1");
//     node1 = ft_lstnew(str);
//
//     ft_lstdelone(node1, del);
//
//     return (0);
//
// }
