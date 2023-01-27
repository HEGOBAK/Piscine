#include "ft.h"

int ft_check_opt(char *arg)
{
    int index;

    index = 1;
    while (arg[index])
    {
        if (!(arg[index] >= '0' && arg[index] <= '9'))
            return (0);
        index++;
    }
    return (1);
}

int ft_default_opts(int argc, char **argv)
{
    int index;
    int offset;
    int fd;
    int count;
    int i;
    int line_count;
    char *content;
    unsigned long byte_read;

    if (ft_check_opt(argv[1]) == 0)
    {
        error_ill_opt(argv[0], argv[1]);
        return (0);
    }
    else if (argc < 3)
        ft_read_stdin();
    else
        offset = ft_atoi(argv[1]);
    
    count = 0;
    index = 2;
    while (index < argc)
    {
        if ((fd = open(argv[index], O_RDONLY)) == -1)
            error_absent(argv[0], argv[index]);
        else
        {
            if (count > 0)
                ft_putstr("\n");
            if (argc > 3)
            {
                ft_seperator(argv[index]);
                count++;
            }
            
            content = read_full(fd, &byte_read);
            line_count = count_line(byte_read, content) + 1;
            if (line_count <= offset)
                display_file(argv[index]);
            else
            {
                i = line_count - offset;
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
    ft_default_opts(argc, argv);
    return (0);
}*/