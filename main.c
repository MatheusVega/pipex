/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:10:54 by mathfern          #+#    #+#             */
/*   Updated: 2021/10/11 21:23:23 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h";

int	main (int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0 && fd2 < 0)
		return (-1);
	pipex(fd1, fd2, argv, envp);
	return (0);
}
