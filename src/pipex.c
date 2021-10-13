/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:57:28 by mathfern          #+#    #+#             */
/*   Updated: 2021/10/11 21:35:13 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h";

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (-1);
	if (child1 == 0)
		return (1);
	child2 = fork();
	if (child2 < 0)
		return (-1);
	if (child2 == 0)
		return (1);
	close(end[0]);
	close(end[1]);
	waitpid();
}
