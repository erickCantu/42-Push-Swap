/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:47:38 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/09 18:24:13 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description:
 *		Adds the node ’new’ at the end of the list.
 *	Return Value:
 *		None
 *	Parameters:
 *		lst: The address of a pointer to the first node of a list.
 *		new: The address of a pointer to the node to be added.
 *	External Function:
 *		None
 */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		(*lst) = new;
	else
	{
		last = ft_lstlast((*lst));
		last -> next = new;
	}
}
/*
int main ()
{
    t_list *node1;
    t_list *node2;
    t_list *node3;
    t_list *node4;

    node1 = ft_lstnew("This is node 1");
    node2 = ft_lstnew("This is node 2");
    node3 = ft_lstnew("This is node 3");
	node4 = ft_lstnew("This is node 4");
    node1 -> next = node2;
    node2 -> next = node3;

    ft_lstadd_back(&node1, node4);

    return (0);

}
	

int main()
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = ft_strdup("lorem");
	char		*str2 = ft_strdup("ipsum");
	char		*str3 = ft_strdup("dolor");
	char		*str4 = ft_strdup("sit");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	
	begin = NULL;
    ft_lstadd_back(&begin, elem);
    printf("Begin ahor es: %s\n", begin ->content);
	ft_lstadd_back(&begin, elem2);
    printf("Begin ahor es: %s\n", begin ->content);
	ft_lstadd_back(&begin, elem3);
    printf("Begin ahor es: %s\n", begin ->content);
	ft_lstadd_back(&begin, elem4);
    printf("Begin ahor es: %s\n", begin ->content);
	return (0);
}*/

/*
int main()
{
	t_list *l = ft_lstnew(strdup("nyacat"));
	t_list *n = ft_lstnew(strdup("OK"));
	ft_lstadd_back(&l, n);

    return (0);
}*/
