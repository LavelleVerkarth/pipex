/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:35:46 by lverkart          #+#    #+#             */
/*   Updated: 2021/07/04 12:35:47 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *str)
{
	write(2, "Error: ", ft_strlen("Error: "));
	write(2, str, ft_strlen(str));
	write(1, "\n", 1);
	return (1);
}

int	ft_error_arg(char *str, char *arg)
{
	write(2, arg, ft_strlen(arg));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(1, "\n", 1);
	return (1);
}

void	ft_free_dup_mass(char **str)
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

int	ft_valid_dop_cmd(t_pipex *pip, char *spl, char **argv)
{
	int	acc;
	int	i;

	acc = -1;
	ft_free_dup_mass(pip->cmd);
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
		i = open(argv[pip->argc], O_CREAT | O_TRUNC | O_RDWR, 0644);
		close(i);
		return (ft_error_arg("command not found", pip->tmpcmd + 1));
	}
	return (0);
}

int	ft_validfaile(int argc, char **argv, t_pipex *pip)
{
	int	fd;

	if (argc != 4)
		return (ft_error("There must be four arguments"));
	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
		return (ft_error_arg("No such file or directory", argv[0]));
	if (ft_valid_dop_cmd(pip, argv[1], argv))
		return (1);
	if (ft_valid_dop_cmd(pip, argv[argc - 2], argv))
		return (1);
	return (0);
}
