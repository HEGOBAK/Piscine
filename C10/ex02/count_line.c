#include "ft.h"

 char	*ft_str_sized_copy(char *dest, char *src, unsigned int src_size)
{
	unsigned int	index;

	index = 0;
	while (index < src_size)
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}

char	*read_full(int fd, unsigned long *total_read)
{
	unsigned int	byte_read;
	char			buffer[BUFFER];
	char			*old;
	char			*dest;

	*total_read = 0;
	dest = malloc(0);
	while ((byte_read = read(fd, buffer, BUFFER)) != 0)
	{
		old = dest;
		if (!(dest = malloc((*total_read + byte_read) * sizeof(char))))
			return (0);
		ft_str_sized_copy(dest, old, *total_read);
		ft_str_sized_copy(dest + *total_read, buffer, byte_read);
		*total_read += byte_read;
		free(old);
	}
	return (dest);
}

int		count_line(unsigned long byte_read, char *content)
{
	unsigned long	index;
	int				line_count;

	index = 0;
	line_count = 0;
	while (index < byte_read)
	{
		if (content[index] == '\n' && index != byte_read - 1)
			line_count++;
		index++;
	}
	return (line_count);
}

/*int   main(int argc, char **argv)
{
    int     fd;
    char    *content;
    unsigned long   byte_read;
    int     line_count;

    fd = open(argv[1], O_RDONLY);
    content = read_full(fd, &byte_read);
    line_count = count_line(byte_read, content);
	printf ("%d", line_count);
    return (0);
}*/
