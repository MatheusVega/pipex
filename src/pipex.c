/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:57:28 by mathfern          #+#    #+#             */
/*   Updated: 2021/11/05 16:58:02 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_freecmd(char ***cmd)
{
	int		i;

	i = -1;
	while ((*cmd)[++i])
		free((*cmd)[i]);
	free(*cmd);
}

void	ft_pipex(int fdin, char *path, char **env, char **cmd)
{
	pid_t	pid;
	int		pfd[2];

	ft_exit(pipe(pfd), "deu ruim pipe");
	ft_exit(pid = fork(), "");
	if (pid)
	{
		close(pfd[1]);
		dup2(pfd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		if (fdin == STDIN_FILENO)
			exit(1);
		else
			ft_execve(path, cmd, env);
		ft_freecmd(&cmd);
	}
}
