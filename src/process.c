/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:20:46 by mathfern          #+#    #+#             */
/*   Updated: 2021/11/05 18:39:16 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	int		size;
	int		i;
	char	*str;

	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	str = (char *)malloc((size + 1) * sizeof(*str));
	i = -1;
	while (*s1)
		str[++i] = *s1++;
	while (*s2)
		str[++i] = *s2++;
	while (*s3)
		str[++i] = *s3++;
	str[++i] = 0;
	return (str);
}

int	numbchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

int	ft_execve(char *path, char **cmd, char **env)
{
	char		**tab;
	char		*tmp;
	int			i;

	i = 0;
	tab = ft_split(path, ':');
	while (tab[i])
	{
		if (cmd[0][0] != '/')
			tmp = ft_str3join(tab[i], "/", cmd[0]);
		else
			tmp = cmd[0];
		execve(tmp, cmd, env);
		free(tmp);
		++i;
	}
	write(2, "command error: ", 15);
	write(2, cmd, numbchar(cmd[0], 0));
	write(2, ": command not found\n", 20);
	exit(127);
}

char	*ft_getPath(char **env)
{
	int	i;

	i = 0;
	while (*env[i] != '\0')
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (0);
}
