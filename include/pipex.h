/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:57:41 by mathfern          #+#    #+#             */
/*   Updated: 2021/11/05 18:42:32 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<signal.h>
# include	<string.h>
# include	<sys/stat.h>
# include	<sys/wait.h>

//aux

void	ft_putstr_fd(char const *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t lenght, size_t size);
void	ft_bzero(void *str, size_t size);
char	**ft_strsplit(char const *s, char c);

//src

int		ft_execve(char *path, char **cmd, char **env);
void	ft_pipex(int fdin, char *path, char **env, char **cmd);
int		ft_childProcess(char **argv, int *end, char **env, char *path);
int		ft_parentProcess(char **argv, int *end, char **env, char *path);
char	*ft_getPath(char **env);
void	ft_freecmd(char ***cmd);
void	ft_exit(int code, char *str);

#endif
