/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:10:15 by masoares          #+#    #+#             */
/*   Updated: 2023/10/14 15:50:57 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_strlen(const char *str);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putunbr_fd(unsigned long nbr, int fd, int size);
int	ft_putnbr_base(unsigned int nbr, char *base, int fd);
int	ft_putnbr_base_sc(unsigned int nbr, int size, char l);
int	ft_count_num(int nbr, int size);
int	ft_count_num2(unsigned int nbr, int size);
int	ft_printf(const char *str, ...);
int	ft_putadd_fd(unsigned long num, int fd);
