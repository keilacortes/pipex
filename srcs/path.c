/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:18:45 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/12/12 23:19:21 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**dir;
	char	*full_path;
	char	*env_path;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	env_path = get_env_path(envp);
	if (!env_path)
		return (NULL);
	dir = ft_split(env_path, ':');
	i = 0;
	while (dir[i])
	{
		full_path = join_path(dir[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_arr(dir);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_arr(dir);
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = find_path(args[0], envp);
	if (!path)
	{
		write(2, args[0], strlen(args[0]));
		write(2, ": command not found\n", 20);
		free_arr(args);
		exit(127);
	}
	execve(path, args, envp);
	free(path);
	free_arr(args);
	pipe_error("pipex");
}
