/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:19:44 by masoares          #+#    #+#             */
/*   Updated: 2023/10/08 20:08:18 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		size;

	size = ft_strlen(s);
	write (fd, s, size);
}

#include <fcntl.h>
int main (void)
{
        int     fd;
        
        fd = open("test", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
        ft_putstr_fd("animal", fd);
        close(fd);
}
