#include "../inc/parking.h"

int		ms_atoi(const char *str)
{
	int nb;
	int sign;

	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\r' ||
			*str == '\t' || *str == '\v')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while (ms_isdigit((int)*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}

int		ms_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ms_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		ms_isalnum(int c)
{
	if (ms_isdigit(c) || ms_isalpha(c))
		return (1);
	return (0);
}

void	ms_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = s;
	while (n--)
		*str++ = '\0';
}

void	*ms_memalloc(size_t size)
{
	void *mem;

	mem = (void *)malloc(size * sizeof(void *));
	if (!mem)
		return (NULL);
	ms_bzero(mem, size);
	return (mem);
}


char	*ms_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = ms_strnew(ms_strlen(s1) + ms_strlen(s2));
	if (!new)
		return (NULL);
	ms_strcpy(new, s1);
	ms_strcat(new, s2);
	return (new);
}


char	*ms_strnew(size_t size)
{
	char *str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ms_bzero(str, size + 1);
	return (str);
}


char	*ms_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = ms_strlen((char *)s);
	dst = ms_strnew(len);
	if (!dst)
		return (NULL);
	while (len--)
		dst[len] = s[len];
	return (dst);
}

void	ms_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ms_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	if (!c && *s == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ms_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ms_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ms_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ms_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[len] = '\0';
	i = 0;
	while (len--)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	return (new);
}

static int		next_line(char **line_fd, char **line, const int fd,
		ssize_t ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line_fd[fd][i] != '\0' && line_fd[fd][i] != '\n')
		i++;
	if (line_fd[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ms_strdup(line_fd[fd]);
		ms_strdel(&line_fd[fd]);
	}
	else if (line_fd[fd][i] == '\n')
	{
		*line = ms_strsub(line_fd[fd], 0, i);
		tmp = ms_strdup(line_fd[fd] + 1 + i);
		free(line_fd[fd]);
		line_fd[fd] = tmp;
		if (line_fd[fd][0] == '\0')
			ms_strdel(&line_fd[fd]);
	}
	return (1);
}


int				get_next_line(const int fd, char **line)
{
	static char			*line_fd[4096];
	char				buff[BUFF_SIZE + 1];
	char				*tmp;
	ssize_t				ret;

	if (fd < 0 || BUFF_SIZE <= 0 || BUFF_SIZE > 2147483647 ||
			read(fd, &tmp, 0) < 0 || line == NULL || fd > 4096 || fd < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (line_fd[fd] == NULL)
			line_fd[fd] = ms_strnew(1);
		tmp = ms_strjoin(line_fd[fd], buff);
		free(line_fd[fd]);
		line_fd[fd] = tmp;
		if (ms_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if ((line_fd[fd] == NULL || line_fd[fd][0] == '\0') && ret == 0)
		return (0);
	return (next_line(line_fd, line, fd, ret));
}

