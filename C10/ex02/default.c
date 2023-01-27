#include "ft.h"

void ft_read_stdin(void)
{
	char	buffer;

	while (read(0, &buffer, 1));
}

void display_file(char *file)
{
    int fd;
	int r;
	char a;

    fd = open(file, O_RDONLY);
	while ((r = read(fd, &a, 1)))
		write (1, &a, 1);
    close(fd);
}

void ft_seperator(char *file)
{
    ft_putstr("==> ");
    ft_putstr(file);
    ft_putstr(" <==\n");
}

int ft_default(int argc, char **argv)
{
    int fd;
    int index;
    int line_count;
    char *content;
    unsigned long byte_read;
    int i;
    int count;

    count = 0;
    index = 1;
    while (index < argc)
    {
        if ((fd = open(argv[index], O_RDONLY)) == -1)
            error_absent(argv[0], argv[index]);
        else
        {
            if (count > 0)
                ft_putstr("\n");
            if (argc > 2)
            {
                ft_seperator(argv[index]);
                count++;
            }
            
            content = read_full(fd, &byte_read);
            line_count = count_line(byte_read, content) + 1;
            if (line_count <= 10)
                display_file(argv[index]);
            else
            {
                i = line_count - 10;
                while (i > 0)
                {
                    while (*content != '\n')
                        content++;
                
                    content++;
                    i--;
                }
                ft_putstr(content);
            }
        }
        index++;
        close(fd);
    }
    return (0);
}

/*int main(int argc, char **argv)
{
    ft_default(argc, argv);
    return (0);
}*/