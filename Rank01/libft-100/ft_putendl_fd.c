/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:28:17 by masoares          #+#    #+#             */
/*   Updated: 2023/10/08 20:07:13 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	size;

	if (fd < 0)
		return ;
	size = ft_strlen(s);
	write(fd, s, size);
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>
int main (void)
{
        int     fd;
        
        fd = open("test", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
        ft_putendl_fd("animal", fd);
        close(fd);
}*/
