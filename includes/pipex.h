/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:18:45 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/12/12 23:19:21 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

// Erros
void	pipe_error(char *msg);

// Utilitários
void	free_arr(char **arr);
void	execute(char *cmd, char **envp);
char	*join_path(char *path, char *cmd);

// Execução
void	pipex(char **infile, char **envp);

#endif
