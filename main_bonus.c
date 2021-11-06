/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:00:06 by mathfern          #+#    #+#             */
/*   Updated: 2021/11/05 22:11:03 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	ft_exit(int code, char *str)
{
	if (code < 0)
	{
		ft_putstr_fd("pipex", 2);
		ft_putstr_fd(str, 2);
		_exit(1);
	}
}

static void	loop(int numbloop, int fdin, char	*path,  char **envp, char **argv)
{
	int		i;
	char	**cmd;

	i = 3;
	while (i < numbloop - 2)
	{
		cmd = ft_split(argv[i++], ' ');
		ft_pipex(fdin, path, envp, cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int		fdin;
	int		fdout;
	char	**cmd1;
	char	**cmd2;

	if (argc < 4)
		ft_exit(-1, "Quantidade de argumentos errada");
	path = ft_getPath(envp);
	if (path == NULL)
		ft_exit(-1, "Não foi possivel ler o path");
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[argc - 2], ' ');
	if (!cmd1)
		ft_exit(-1, "cmd");
	ft_exit(fdout = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 777), "outfile error");
	ft_exit(fdin = open(argv[1], O_RDONLY), "Erro no infile");
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	ft_pipex(fdin, path, envp, cmd1);
	loop(argc, fdin, path, envp, argv);
	ft_execve(path, cmd2, envp);
	ft_freecmd(&cmd2);
	return (1);
}
