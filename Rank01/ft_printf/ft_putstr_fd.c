/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:19:44 by masoares          #+#    #+#             */
/*   Updated: 2023/10/14 15:56:59 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	size;

	if (s == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	size = ft_strlen(s);
	write (fd, s, size);
	return (size);
}
/*
#include <fcntl.h>
int main (void)
{
	int     fd;
	
	fd = open("test", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
	ft_putstr_fd("animal", fd);
	close(fd);
}*/
