/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilus_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:35:44 by lverkart          #+#    #+#             */
/*   Updated: 2021/07/05 09:35:46 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ftb_pipex_parse(char **env, t_pipex *pip)
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

int	get_next_line(char **line)
{
	char	buff;
	int		i;
	char	*tmp;

	i = 0;
	if (!line)
		return (-1);
	tmp = malloc(sizeof(char) * 100);
	while (read(0, &buff, 1) > 0)
	{
		tmp[i] = buff;
		if (tmp[i] == '\n')
		{
			tmp[i + 1] = '\0';
			*line = tmp;
			return (1);
		}
		i++;
	}
	tmp[i] = '\0';
	*line = tmp;
	return (0);
}

void	ftb_odd_even(t_pipex *pip, int *fd, int *fd2, char **argv)
{
	if (pip->odd % 2 == 0)
		ftb_even_pipex(fd2, fd, pip, argv);
	else
		ftb_even_pipex(fd, fd2, pip, argv);
}
