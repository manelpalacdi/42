#include "../pipex.h"

void free_matrix(char **m)
{
    int i;

    i = 0;
    if (!m)
        return ;
    while(m[i])
    {
        free(m[i]);
        i++;
    }
    free(m);
}

static int  get_path_index(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
            return (i);
        i++;
    }
    return (-1);
}

char    *get_path(char *cmd, char **env)
{
    int     i;
    char    **paths;
    char    **s_cmd;
    char    *path_part;
    char    *path_cmd;

    paths = ft_split(env[get_path_index(env)] + 5, ':');
    s_cmd = ft_split(cmd, ' ');
	i = 0;
    while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(path_cmd, F_OK | X_OK) == 0)
		{
            free_matrix(paths);
			free_matrix(s_cmd);
			return (path_cmd);
		}
		free(path_cmd);
        i++;
	}
    free_matrix(paths);
    free_matrix(s_cmd);
    return (cmd);
}
