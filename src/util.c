# include "../inc/parking.h"
# include <fcntl.h>

int     open_files(char *file)
{
    int fd;
    char buff;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    if (read(fd, &buff, 0) == -1)
        return (-1);
    return (fd);
}

int     get_value(int fd)
{
    char *buff;
    int nb;

    get_next_line(fd, &buff);
    nb = ft_atoi(buff);
    free(buff);
    return (nb);
}
