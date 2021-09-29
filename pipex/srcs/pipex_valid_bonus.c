/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_valid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:27:53 by lverkart          #+#    #+#             */
/*   Updated: 2021/07/05 09:27:56 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ftb_error(char *str)
{
	write(2, "Error: ", ft_strlen("Error: "));
	write(2, str, ft_strlen(str));
	write(1, "\n", 1);
	return (1);
}

int	ftb_error_arg(char *str, char *arg)
{
	write(2, arg, ft_strlen(arg));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(1, "\n", 1);
	return (1);
}

void	ftb_free_dup_mass(char **str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		;
	while (--i >= 0)
		free(str[i]);
	free(str);
}

int	ftb_valid_dop_cmd(t_pipex *pip, char *spl, char **argv)
{
	int	acc;
	int	i;

	acc = -1;
	ftb_free_dup_mass(pip->cmd);
	pip->cmd = ft_split(spl, ' ');
	free(pip->tmpcmd);
	pip->tmpcmd = ft_strjoin("/", pip->cmd[0]);
	i = -1;
	while (pip->path[++i] != NULL && acc == -1)
	{
		free(pip->cmd[0]);
		pip->cmd[0] = ft_strjoin(pip->path[i], pip->tmpcmd);
		acc = access(pip->cmd[0], F_OK);
	}
	if (acc == -1)
	{
		if (pip->mod == 0)
			i = open(argv[pip->argc], O_CREAT | O_TRUNC | O_RDWR, 0644);
		else
			i = open(argv[pip->argc], O_CREAT | O_RDWR, 0644);
		close(i);
		return (ftb_error_arg("command not found", pip->tmpcmd + 1));
	}
	return (0);
}

int	ftb_validfaile(int argc, char **argv, t_pipex *pip)
{
	int	fd;
	int	i;

	if (argc < 4)
		return (ftb_error("Not enough arguments"));
	if (pip->mod == 0)
	{
		fd = open(argv[0], O_RDONLY);
		if (fd < 0)
			return (ftb_error_arg("No such file or directory", argv[0]));
	}
	i = 0;
	while (++i < argc - 1)
		if (ftb_valid_dop_cmd(pip, argv[i], argv))
			return (1);
	return (0);
}
