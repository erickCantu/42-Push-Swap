/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:20:46 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/11/30 15:24:35 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	s: The string to output.
	fd: The file descriptor on which to write.

	Outputs the string ’s’ to the specified file descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &(*s), 1);
		s++;
	}
}
