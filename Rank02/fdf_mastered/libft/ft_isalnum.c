/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:51:25 by masoares          #+#    #+#             */
/*   Updated: 2023/10/05 19:27:46 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	int	a;

	a = 0;
	if ((c >= 'A' && c <= 'Z') || \
			(c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		a = 1;
	return (a);
}