/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:21:47 by lverkart          #+#    #+#             */
/*   Updated: 2021/07/03 18:21:48 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ftb_pipex_process(t_pipex *pip, int *fd, char **env, char **argv)
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
	ftb_free_dup_mass(pip->cmd);
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

void	ftb_pipex_parent_process(t_pipex *pip, int *fd, char **env, char **argv)
{
	int	sfd;
	int	i;

	if (pip->mod == 0)
		sfd = open(argv[pip->argc], O_CREAT | O_TRUNC | O_RDWR, 0644);
	else
		sfd = open(argv[pip->argc], O_CREAT | O_APPEND | O_RDWR, 0644);
	dup2(sfd, 1);
	close(sfd);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	ftb_free_dup_mass(pip->cmd);
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

void	ftb_even_pipex(int *fd, int *fd2, t_pipex *pip, char **argv)
{
	int	id;

	if (pipe(fd2) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit(ftb_error("An error ocurred with opening the pipe"));
	}
	id = fork();
	if (id < 0)
	{
		close(fd2[0]);
		close(fd2[1]);
		close(fd[0]);
		close(fd[1]);
		exit(ftb_error("The creation of a child process was unsuccessful"));
	}
	if (id == 0)
		ftb_pipex_cycle_process(pip, fd, fd2, argv[pip->odd]);
	close(fd[0]);
	close(fd[1]);
}

void	ftb_pipex(t_pipex *pip, char **argv, char **env)
{
	int	fd[2];
	int	id;
	int	fd2[2];

	if (pipe(fd) == -1)
		exit(ftb_error("An error ocurred with opening the pipe"));
	id = fork();
	if (id < 0)
	{
		close(fd[0]);
		close(fd[1]);
		exit(ftb_error("The creation of a child process was unsuccessful"));
	}
	if (id == 0 && pip->mod == 0)
		ftb_pipex_process(pip, fd, env, argv + 1);
	else if (id == 0 && pip->mod == 1)
		ftb_pipex_process_mod(pip, fd, env, argv + 1);
	pip->odd = 2;
	while (++pip->odd < pip->argc)
		ftb_odd_even(pip, fd, fd2, argv);
	if (pip->odd % 2 == 0)
		ftb_pipex_parent_process(pip, fd2, env, argv + 1);
	else
		ftb_pipex_parent_process(pip, fd, env, argv + 1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pip;

	if (argc > 3 && ft_strnstr(argv[1], "here_doc", 8) != NULL)
	{
		pip.mod = 1;
		argv++;
		argc -= 1;
	}
	else
		pip.mod = 0;
	pip.tmpcmd = NULL;
	pip.cmd = NULL;
	pip.argc = argc - 2;
	pip.env = env;
	ftb_pipex_parse(env, &pip);
	if (ftb_validfaile(argc - 1, argv + 1, &pip) == 1)
		exit (1);
	ftb_pipex(&pip, argv, env);
}
