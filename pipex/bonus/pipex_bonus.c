/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:29:14 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/12/13 19:28:30 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	heredoc(char *del)
{
	int		fd;
	char	*line;
	int		cnt;

	fd = open("archivotem", O_CREAT | O_TRUNC |O_RDWR);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!ft_strncmp(line, del, ft_strlen(line) - 1))
			break ;
		else
		{
			cnt = ft_strlen(line);
			write(fd, line, cnt);
			write(fd, "\n", cnt + 1);
		}
		free(line);
	}
	return (fd);
}

void	envario(int fd1, char **env, char *command)
{
	int	fd[2];
	int	pid;
	int	fail;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		son(command, env, fd, fd1);
	else
	{
		waitpid(pid, &fail, WNOHANG);
		if (fail == 128)
			exit(128);
		if (fail == 1)
			exit(1);
		daddy(fd);
	}
}

void	son(char *command, char **env, int fd[2], int fd1)
{
	char	**arg;
	char	*path;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (fd1 == STDIN_FILENO)
		exit(1);
	arg = ft_split(command, ' ');
	path = ft_path(arg[0], env);
	if (execve(path, arg, env) < 0)
		exit(1);
}
void	daddy(int fd[2])
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
}
void	ft_print_matrix(char **matrix)
{
	int	cnt;

	cnt = 0;
	while (matrix[cnt])
	{
		printf("%s\n", matrix[cnt]);
		cnt++;
	}
}
char	*ft_path(char *cmdname, char **env)
{
	int		cnt;
	char	**path;
	char	*comand;

	cnt = 0;
	while (env[cnt] != NULL && ft_strncmp(env[cnt], "PATH=", 5))
		cnt++;
	if (env[cnt] == NULL)
		return (NULL);
	path = ft_split(env[cnt] + 5, ':');
	cnt = 0;
	while (path[cnt])
	{
		path[cnt] = ft_strjoin(path[cnt], "/");
		comand = ft_strjoin(path[cnt], cmdname);
		if ((access(comand, F_OK) == 0))
			return (comand);
		free(comand);
		cnt++;
	}
	return (NULL);
}
int	main(int argc, char **argv, char **env)
{
	int		cnt;
	int		fd1;
	int		fd2;
	char	**arg;
	char	*path;

	cnt = 3;
	if (!ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])))
	{
		fd2 = open(argv[argc - 1], O_CREAT | O_APPEND | O_WRONLY , 0664);
		fd1 = heredoc(argv[2]);
	}
	else
	{
		fd2 = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY , 0664);
		fd1 = open(argv[1], O_RDONLY);
	}
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	envario(fd1, env, argv[2]);
	while (argv[cnt] && cnt < argc - 2)
	{
		envario(STDOUT_FILENO, env, argv[cnt]);
		cnt++;
	}
	arg = ft_split(argv[cnt], ' ');
	path = ft_path(arg[0], env);
	if (execve(path, arg, env) < 0)
		exit(1);
}
