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
