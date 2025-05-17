#include <sys/types.h>		//fork
#include <unistd.h>			//write
#include <sys/wait.h>		//waitpid
#include <string.h>			//strcmp

int error_msg(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int builtin_cd(char **av, int i)
{
	if (i != 2)
		return error_msg("error: cd: bad arguments\n");
	else if (chdir(av[1]) == -1)
		return error_msg("error: cd: bad arguments "), error_msg(av[1]), error_msg("\n");
	return (0);
}

int exec_cmds(char **av, int i, char **env)
{
	int fd[2];
	int status;
	int is_pipe;
	
	if (av[i] && strcmp(av[i], "|") == 0)
		is_pipe = 1;
	else
		is_pipe = 0;
	if (is_pipe && pipe(fd) == -1)
		return (error_msg("error: fatal\n"));
	int pid = fork();
	if (!pid)
	{
		av[i] = 0;
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (error_msg("error: fatal\n"));
		execve(*av, av, env);
		return (error_msg("error: cannot execute "), error_msg(*av), error_msg("\n"));
	}
	waitpid(pid, &status, 0);
	if(is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (error_msg("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **env)
{
	int i = 0;
	int status = 0;

	(void)ac;
	while(av[i] && av[++i])
	{
		av += i;
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (!strcmp(av[0], "cd"))
			status = builtin_cd(av, i);
		else
			status = exec_cmds(av, i, env);
	}
	return (status);
}
