/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:37:37 by mathfern          #+#    #+#             */
/*   Updated: 2021/11/05 17:56:38 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	int	ft_ret_Length(char const *s, char c)
{
	int	len;
	int	valid;
	int	count;

	len = 0;
	valid = 1;
	count = 0;
	while (s[count] != 0)
	{
		if (s[count] != c && valid)
		{
			len++;
			valid = 0;
		}
		else if (s[count++] == c)
			valid = 1;
	}
	return (len);
}

static	size_t	ft_len(const char *s, char c)
{
	size_t	countA;
	size_t	countB;

	countA = 0;
	countB = 0;
	while (s[countA] == c)
		countA++;
	while (s[countA] && s[countA] != c)
	{
		countA++;
		countB++;
	}
	return (countB);
}

static	void	ft_free(char **s)
{
	int	count;

	count = 0;
	while (s[count])
	{
		free(s[count]);
		count++;
	}
	free(s);
}

static	char	**ft_array(char const *s, char c, char **words, char **words2)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
		{
			count++;
			continue ;
		}
		if (s[count] != c)
		{
			*words = ft_substr(&s[count], 0, ft_len(&s[count], c));
			if (!words)
			{
				ft_free(words);
				return (NULL);
			}
			count = count + ft_len(&s[count], c);
			words ++;
		}
	}
	*words = NULL;
	return (words2);
}

char	**ft_split(char const *s, char c)
{
	int		count_word;
	char	**words;

	if (!s)
		return (NULL);
	count_word = ft_ret_Length(s, c);
	words = (char **)ft_calloc(sizeof(char *), (count_word + 1));
	if (!words)
		return (NULL);
	words = ft_array(s, c, words, words);
	if (words == NULL)
		return (NULL);
	return (words);
}
