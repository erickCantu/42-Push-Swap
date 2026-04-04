/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:25:55 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/11/30 15:37:10 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	s: The string to output.
	fd: The file descriptor on which to write.

	Outputs the string ’s’ to the specified file descriptor followed by 
	a newline.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &(*s), 1);
		s++;
	}
	write(fd, "\n", 1);
}
