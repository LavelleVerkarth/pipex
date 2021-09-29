/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:23:36 by lverkart          #+#    #+#             */
/*   Updated: 2021/06/07 15:23:39 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_pipex
{
	char	**path;
	char	**cmd;
	char	*tmpcmd;
	int		argc;
	int		mod;
	char	*heredoc;
	int		odd;
	char	**env;
}				t_pipex;

int		ft_error(char *str);
void	ft_free_dup_mass(char **str);
int		ft_validfaile(int argc, char **argv, t_pipex *pip);
int		ftb_error(char *str);
void	ftb_free_dup_mass(char **str);
int		ftb_validfaile(int argc, char **argv, t_pipex *pip);
void	ftb_pipex_cycle_process(t_pipex *pip, int *fd, int *fd2, char *argv);
void	ftb_pipex_process_mod(t_pipex *pip, int *fd, char **env, char **argv);
void	ftb_even_pipex(int *fd, int *fd2, t_pipex *pip, char **argv);
void	ftb_pipex_parse(char **env, t_pipex *pip);
int		get_next_line(char **line);
void	ftb_odd_even(t_pipex *pip, int *fd, int *fd2, char **argv);

#endif
