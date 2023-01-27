#include "ft.h"

int ft_strlen(char *str)
{
    int index;

    index = 0;
    while (str[index])
        index++;
    return (index);
}

int ft_opt_c(int argc, char **argv)
{
    int index;
    char *offset_c;
    unsigned long offset;
    char *content;
    unsigned long byte_read;
    int fd;
    int count;
    int i;
    int a;

    offset = 0;
    byte_read = 0;
    if (argv[1][2] != '\0')
    {
        byte_read = 1;
        index = 2;
        offset_c = (char*)malloc(sizeof(char) * (ft_strlen(argv[1] - 2)));
        while (argv[1][index])
        {
            offset_c[offset] = argv[1][index];
            offset++;
            index++;
        }
        offset_c[offset] = '\0';
        if ((offset = ft_atoi(offset_c)) == 0)
        {
            error_ill_off(argv[0], offset_c);
            return (0);
        }
        free(offset_c);
    }
    else if (argc < 3)
            error_opt_requirements(argv[0]);
    else
    {
        if ((offset = ft_atoi(argv[2])) == 0)
        {
            error_ill_off(argv[0], argv[2]);
            return (0);
        }
    }

    if (byte_read == 1)
        index = 2;
    else
        index = 3;

    count = 0;
    a = index + 1;
    if (index == argc)
        ft_read_stdin();

    while (index < argc)
    {
        if ((fd = open(argv[index], O_RDONLY)) == -1)
            error_absent(argv[0], argv[index]);
        else
        {
            if (count > 0)
                ft_putstr("\n");
            if (argc > a)
            {
                ft_seperator(argv[index]);
                count++;
            }
            
            content = read_full(fd, &byte_read);
            if (byte_read <= offset)
                display_file(argv[index]);
            else
            {
                i = byte_read - offset;
                while (i > 0)
                {
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
    ft_opt_c(argc, argv);
    return (0);
}*/