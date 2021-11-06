/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:03:30 by mathfern          #+#    #+#             */
/*   Updated: 2021/10/28 20:05:08 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	sizesrc;
	size_t	count;

	if (!(dest) || !(src))
		return (0);
	if (destsize == 0)
		return (ft_strlen(src));
	count = 0;
	sizesrc = ft_strlen(src);
	while (src[count] != '\0' && count < destsize - 1)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (sizesrc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (s == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		ret = ft_calloc(sizeof(char), 1);
		if (!ret)
			return (NULL);
		return (ret);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ret = (char *)ft_calloc((len + 1), sizeof(char));
	if (ret == NULL)
		return (0);
	ft_strlcpy(ret, &s[start], len + 1);
	return (ret);
}
