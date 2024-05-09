#include "pipex.h"

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
