/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:37:07 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/12/06 20:21:03 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description:
 *		Allocates memory (using malloc(3)) and returnsa new node. 
 *		The ’content’ member variable is initialized with the given 
 *		parameter ’content’. The variable ’next’ is initialized to 
 *		NULL.
 *	Return Value:
 *		A pointer to the new node
 *	Parameters:
 *		content: The content to store in the new node.
 *	External Function:
 *		malloc 
 */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
