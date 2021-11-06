/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:05:19 by mathfern          #+#    #+#             */
/*   Updated: 2021/10/28 20:05:27 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	*ft_calloc(size_t lenght, size_t size)
{
	void	*pont;

	pont = malloc(lenght * size);
	if (!pont)
		return (NULL);
	ft_bzero(pont, lenght * size);
	return (pont);
}
