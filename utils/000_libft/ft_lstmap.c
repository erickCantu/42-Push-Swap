/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:55:04 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/20 17:37:33 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description:
 *		Iterates through the list ’lst’, applies the function ’f’ 
 *		to each node’s content, and creates a new list resulting of 
 *		the successive applications of the function ’f’. 
 *		The ’del’ function is used to delete the content of a node 
 *		if needed.
 *	Return Value:
 *		The new list.
		NULL if the allocation fails.
 *	Parameters:
 *		lst: The address of a pointer to a node.f
 *		f: The address of the function applied to each node’s content.
 *		del: The address of the function used to delete a node’s 
 *		     content if needed.
 *	External Function:
 *		malloc, free
 */

#include "libft.h"

static t_list	*ft_lstmap_del(void *content_tmp, void (*del)(void *))
{
	del(content_tmp);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_res;
	t_list	*node_tmp;
	void	*content_tmp;

	if (!lst || lst == NULL || !f || !del)
		return (NULL);
	content_tmp = f(lst -> content);
	lst_res = ft_lstnew(content_tmp);
	if (!lst_res)
		return (ft_lstmap_del(content_tmp, del));
	node_tmp = lst_res;
	lst = lst -> next;
	while (lst)
	{
		content_tmp = f(lst -> content);
		node_tmp = ft_lstnew(content_tmp);
		if (!node_tmp)
		{
			ft_lstclear(&(lst_res), del);
			return (ft_lstmap_del(content_tmp, del));
		}
		ft_lstadd_back(&(lst_res), node_tmp);
		lst = lst -> next;
	}
	return (lst_res);
}
/*
void ft_del(void *element)
{
	free(element);
}

void *ft_map(void *ct)
{
	int i;
	void	*c;
	char	*pouet;

	c = ct;
	i = -1;
	pouet = (char *)c;
	while (pouet[++i])
		if (pouet[i] == 'o')
			pouet[i] = 'a';
	return (c);
}

int	main()
{
	t_list	*n1;
	// t_list	*n2;
	// t_list	*n3;
	t_list	*list;
	char	*str1;
	// 

	str1 = ft_strdup("node 1\n");
	// str2 = ft_strdup("node 2\n");
	// str3 = ft_strdup("node 3\n");
	
	n1 = ft_lstnew(str1);
	// n2 = ft_lstnew(str2);
	// n3 = ft_lstnew(str3);

	// n1 ->next = n2;
	// n2 ->next = n3;

	list = ft_lstmap(n1, &ft_map, &ft_del);

	// while (list)
	// {
	// 	printf("el nodo es el nade: %s", (char *) list -> content);
	// 	list = list -> next;
	// }

	free(n1);
	// free(n2);
	// free(n3);
	ft_lstclear(&list, ft_del);
	//free(str1);
	return(0);
}


int main()
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*list;
	char		*str = ft_strdup("lorem");
	char		*str2 = ft_strdup("ipsum");
	char		*str3 = ft_strdup("dolor");
	char		*str4 = ft_strdup("sit");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);

	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	list = ft_lstmap(elem, &ft_map, &ft_del);

}
	*/
