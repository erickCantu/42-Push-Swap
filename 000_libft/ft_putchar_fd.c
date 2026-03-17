/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:07:52 by ecantu-p          #+#    #+#             */
/*   Updated: 2025/11/30 15:16:07 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    c: The character to output.
    fd: The file descriptor on which to write.

    Outputs the character ’c’ to the specified file descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
