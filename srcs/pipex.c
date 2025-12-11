/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:18:45 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/12/12 23:19:21 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(char **argv, char **envp, int fd[2])
{
	int	fd_in;

	close(fd[0]);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		pipe_error(argv[1]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execute(argv[2], envp);
}

void	child_process2(char **argv, char **envp, int fd[2])
{
	int	fd_out;

	close(fd[1]);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
		pipe_error(argv[4]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execute(argv[3], envp);
}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) < 0)
		pipe_error("pipe");
	pid1 = fork();
	if (pid1 < 0)
		pipe_error("fork");
	if (pid1 == 0)
		child_process1(argv, envp, fd);
	pid2 = fork();
	if (pid2 < 0)
		pipe_error("fork");
	if (pid2 == 0)
		child_process2(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
