#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include<unistd.h>

int	msg_err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	builtin_cd(char **av, int i)
{
	if (i != 2)
		return (msg_err("Error: cd: bad arguments\n"));
	else if (chdir(av[1]) == -1)
		return (msg_err("Error: cd: cannot change directoy to "), msg_err(av[1]), msg_err("\n"));
	return (0);
}

int	other_cmds(char **av, int i, char **env)
{
	int fd[2];
	int status;
	int	is_pipe;

	if (av[i] && strcmp(av[i], "|") == 0)
		is_pipe = 1;
	else
		is_pipe = 0;
	if (is_pipe && pipe(fd) == -1)
		return (msg_err("error : fatal\n"));
	int	pid = fork();
	if (!pid)
	{
		av[i] = 0;
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (msg_err("error : fatal\n"));
		execve(*av, av, env);
		return (msg_err("error: cannot execute "), msg_err(*av), msg_err("\n"));
	}
	waitpid(pid, &status, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (msg_err("error : fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **env)
{
	int	i = 0;
	int	status = 0;

	(void)ac;
	while (av[i] && av[++i])
	{
		av += i;
		i = 0;
		while (av[i] && strcmp(";", av[i]) && strcmp("|", av[i]))
			i++;
		if (strcmp(av[0], "cd") == 0)
			status = builtin_cd(av, i);
		else
			status = other_cmds(av, i, env);
		return (status);
	}
}