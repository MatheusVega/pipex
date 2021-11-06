/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:40:24 by mathfern          #+#    #+#             */
/*   Updated: 2021/10/28 20:06:30 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_bzero(void *str, size_t size)
{
	unsigned char	*newsrc;

	while (size--)
	{
		newsrc = (unsigned char *)str;
		*newsrc = 0;
		str++;
	}
}
