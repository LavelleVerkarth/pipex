/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mod_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:37:27 by lverkart          #+#    #+#             */
/*   Updated: 2021/07/05 09:37:28 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ftb_pipex_cycle_process(t_pipex *pip, int *fd, int *fd2, char *argv)
{
	int	i;

	close(fd[1]);
	close(fd2[0]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd2[1], 1);
	close(fd2[1]);
	ftb_free_dup_mass(pip->cmd);
	pip->cmd = ft_split(argv, ' ');
	free(pip->tmpcmd);
	pip->tmpcmd = ft_strjoin("/", pip->cmd[0]);
	i = -1;
	while (pip->path[++i] != NULL)
	{
		free(pip->cmd[0]);
		pip->cmd[0] = ft_strjoin(pip->path[i], pip->tmpcmd);
		execve(pip->cmd[0], pip->cmd, pip->env);
	}
	exit(1);
}

void	ftb_pipex_mod_proc(t_pipex *pip, char **argv, int *fd, int *fd2)
{
	char	*line;
	char	*tmp;

	pip->heredoc = ft_strdup("");
	get_next_line(&line);
	while (ft_strnstr(line, argv[0], ft_strlen(argv[0])) == NULL)
	{
		tmp = pip->heredoc;
		pip->heredoc = ft_strjoin(pip->heredoc, line);
		free(tmp);
		get_next_line(&line);
	}
	free (line);
	write(fd2[1], pip->heredoc, ft_strlen(pip->heredoc));
	close(fd2[1]);
	dup2(fd2[0], 0);
	close(fd2[0]);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	ftb_free_dup_mass(pip->cmd);
	pip->cmd = ft_split(argv[1], ' ');
	free(pip->tmpcmd);
	pip->tmpcmd = ft_strjoin("/", pip->cmd[0]);
}

void	ftb_pipex_process_mod(t_pipex *pip, int *fd, char **env, char **argv)
{
	int		i;
	int		fd2[2];

	if (pipe(fd2) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit(ftb_error("An error ocurred with opening the pipe"));
	}
	ftb_pipex_mod_proc(pip, argv, fd, fd2);
	i = -1;
	while (pip->path[++i] != NULL)
	{
		free(pip->cmd[0]);
		pip->cmd[0] = ft_strjoin(pip->path[i], pip->tmpcmd);
		execve(pip->cmd[0], pip->cmd, env);
	}
	exit(1);
}
