/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:29:14 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/02/10 15:49:14 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	son(char **argv, char **env, int pipefd[2])
{
	int		fd1;
	char	**arg;
	char	*comand;

	arg = ft_split(argv[2], ' ');
	comand = ft_path(arg[0], env);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
	{
		ft_printf(ROJO "[FATAL ERROR] no infile \n");
		exit(1);
	}
	close(pipefd[0]);
	dup2(fd1, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd1);
	close(pipefd[1]);
	if (execve(comand, arg, env) < 0)
		return (1);
	return (0);
}

void	daddy(char **argv, char **env, int pipefd[2])
{
	int		fd2;
	char	**arg;
	char	*comand;

	arg = ft_split(argv[3], ' ');
	comand = ft_path(arg[0], env);
	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0)
	{
		//write(2,"error", 5);
		exit(1);
	}
	close(pipefd[1]);
	dup2(fd2, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	close(fd2);
	if (execve(comand, arg, env) < 0)
		exit(1);
}

void	ft_print_matrix(char **matrix)
{
	int	cnt;

	cnt = 0;
	while (matrix[cnt])
	{
		ft_printf("%s\n", matrix[cnt]);
		cnt++;
	}
}

char	*route(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if ((((((((((access(cmd, F_OK) == 0))))))))))
			return (cmd);
		ft_printf(ROJO "[FATAL ERROR]exe not found\n");
		exit(1);
	}
	return (0);
}

char	*ft_path(char *cmdname, char **env)
{
	int		cnt;
	char	**path;
	char	*comand;

	if (route(cmdname))
		return (route(cmdname));
	cnt = 0;
	while (env[cnt] != NULL && ft_strncmp(env[cnt], "PATH=", 5))
		cnt++;
	if(env[cnt] == NULL)
		ft_printf(ROJO "[FATAL ERROR]conan not found \n");
		return(NULL);
	path = ft_split(env[cnt] + 5, ':');
	cnt = 0;
	while (path[cnt])
	{
		path[cnt] = ft_strjoin(path[cnt], "/");
		comand = ft_strjoin(path[cnt], cmdname);
		if (access(comand, F_OK) == 0)
			return (comand);
		free(comand);
		cnt++;
	}
	if(path[cnt] == NULL)
		ft_printf(ROJO "[FATAL ERROR]conan not found \n");
	return (NULL);
}

void	pipex(char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;
	int		fail;

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
	{
		exit(1);
	}
	if (pid == 0)
		son(argv, env, pipefd);
	if (pid > 0)
	{
		waitpid(pid, &fail, WNOHANG);
		if (fail >= 128)
			exit(128);
		if (fail == 1)
			exit(1);
		daddy(argv, env, pipefd);
	}
}

// void ft_leaks(void)
// {
// 	system("leaks -q pipex");
// }

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		ft_printf(ROJO "[FATAL ERROR] wrong number of arguments\n");
		return (1);
	}
	else
		pipex(argv, env);
}
