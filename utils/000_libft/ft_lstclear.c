/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:51:13 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/08 18:17:01 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description:
 *		Deletes and frees the given node and all its successors, 
 *		using the function ’del’ and free(3).
 *		Finally, set the pointer to the list to NULL.
 *	Return Value:
 *		None
 *	Parameters:
 *		lst: The address of a pointer to a node.
 *		del: The address of the function used to delete the content 
 *		of the node.
 *	External Function:
 *		free
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*tmp;

	if (!(*lst))
		return ;
	while ((*lst))
	{
		tmp = (*lst)-> next;
		ft_lstdelone((*lst), del);
		(*lst) = tmp;
	}
	*lst = NULL;
	tmp = NULL;
}

/*
void    lstdelone_f(void *d)
{
    free(d);
}

int main()
{
    t_list	*l1;
    t_list  *l2;
    t_list  *l3;
    t_list  *l4;
    char *str1;
    char *str2;
    char *str3;
    char *str4;
    str1 = strdup("ny");
    str2 = strdup("#T");
    str3 = strdup("no");
    str4 = strdup("fi");

    l1 = ft_lstnew(str1);
	l2 = ft_lstnew(str2);
    l3 = ft_lstnew(str3);
    l4 = ft_lstnew(str4);
    l1 -> next = l2;
    l2 -> next = l3;
    l3 -> next = l4;
    
    ft_lstclear(&l1, lstdelone_f);
    l1 = NULL;
    l2 = NULL;

    return (0);
}

int main()
{
    //t_list	**lst;
    t_list  *l;
    
    //lst = (t_list **)malloc(sizeof(t_list));
	l = (t_list *)malloc(sizeof(t_list));
    //(*lst) -> next = l;
    l = NULL;
    ft_lstclear(&l, lstdelone_f);

    return (0);
}

int main()
{    
    t_list  *l;
    char    *str;
    
    str = strdup("nyancat");
    
	l = (t_list *)malloc(sizeof(t_list));
    l = ft_lstnew(str);
    
    ft_lstclear(&l, lstdelone_f);

    return (0);
}
*/
