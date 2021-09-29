/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:50:15 by lverkart          #+#    #+#             */
/*   Updated: 2021/06/06 15:50:17 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_parse(char **env, t_pipex *pip)
{
	int	i;
	int	ex;

	i = -1;
	ex = 0;
	while (ex == 0 && env[++i])
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
			ex = 1;
	pip->path = ft_split(env[i], ':');
}

void	ft_pipex_process(t_pipex *pip, int *fd, char **env, char **argv)
{
	int	sfd;
	int	sfd1;
	int	i;

	sfd = open(argv[0], O_RDWR);
	sfd1 = open(argv[pip->argc], O_CREAT | O_TRUNC | O_RDWR, 0644);
	dup2(sfd, 0);
	close(sfd);
	close(sfd1);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	ft_free_dup_mass(pip->cmd);
	pip->cmd = ft_split(argv[1], ' ');
	free(pip->tmpcmd);
	pip->tmpcmd = ft_strjoin("/", pip->cmd[0]);
	i = -1;
	while (pip->path[++i] != NULL)
	{
		free(pip->cmd[0]);
		pip->cmd[0] = ft_strjoin(pip->path[i], pip->tmpcmd);
		execve(pip->cmd[0], pip->cmd, env);
	}
	exit(1);
}

void	ft_pipex_parent_process(t_pipex *pip, int *fd, char **env, char **argv)
{
	int	sfd;
	int	i;

	sfd = open(argv[pip->argc], O_CREAT | O_TRUNC | O_RDWR, 0644);
	dup2(sfd, 1);
	close(sfd);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	ft_free_dup_mass(pip->cmd);
	pip->cmd = ft_split(argv[pip->argc - 1], ' ');
	free(pip->tmpcmd);
	pip->tmpcmd = ft_strjoin("/", pip->cmd[0]);
	i = -1;
	while (pip->path[++i] != NULL)
	{
		free(pip->cmd[0]);
		pip->cmd[0] = ft_strjoin(pip->path[i], pip->tmpcmd);
		execve(pip->cmd[0], pip->cmd, env);
	}
	exit(1);
}

void	ft_pipex(t_pipex *pip, char **argv, char **env)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		exit(ft_error("An error ocurred with opening the pipe"));
	id = fork();
	if (id < 0)
	{
		close(fd[0]);
		close(fd[1]);
		exit(ft_error("The creation of a child process was unsuccessful"));
	}
	if (id == 0)
		ft_pipex_process(pip, fd, env, argv + 1);
	wait(0);
	ft_pipex_parent_process(pip, fd, env, argv + 1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pip;

	pip.cmd = NULL;
	pip.tmpcmd = NULL;
	pip.argc = argc - 2;
	ft_pipex_parse(env, &pip);
	if (ft_validfaile(argc - 1, argv + 1, &pip) == 1)
		exit (1);
	ft_pipex(&pip, argv, env);
}
