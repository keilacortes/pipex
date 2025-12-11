/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:18:45 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/12/12 23:19:21 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_error(char *msg)
{
	perror(msg);
	exit(1);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*join_path(char *path, char *cmd)
{
	char	*temp;
	char	*path_cmd;

	temp = ft_strjoin(path, "/");
	path_cmd = ft_strjoin(temp, cmd);
	free(temp);
	return (path_cmd);
}
