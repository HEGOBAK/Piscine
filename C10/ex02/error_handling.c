#include "ft.h"

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write (1, &str[i], 1);
        i++;
    }
}

void error_absent(char *program_name, char *file)
{
    ft_putstr(program_name);
    ft_putstr(": ");
    ft_putstr(file);
    ft_putstr(": ");
    ft_putstr("No such file or directory\n");
}

void error_ill_opt(char *program_name, char *opt)
{
    ft_putstr(program_name);
    ft_putstr(": ");
    ft_putstr("illegal option -- ");
    ft_putstr(opt);
    ft_putstr("\n");
}

void error_ill_off(char *program_name, char *off)
{
    ft_putstr(program_name);
    ft_putstr(": ");
    ft_putstr("illegal offset -- ");
    ft_putstr(off);
    ft_putstr("\n");
}

void error_opt_requirements(char *program_name)
{
    ft_putstr(program_name);
    ft_putstr(": ");
    ft_putstr("option requires an argument -- c\n");
    ft_putstr("usage: ");
    ft_putstr(program_name);
    ft_putstr(" [-c #][file...]\n");
}

void error_inv_opt(char *program_name, char opt)
{
    ft_putstr(program_name);
    ft_putstr(": ");
    ft_putstr("invalid option -- ");
    write (1, &opt, 1);
    ft_putstr("\n");
    ft_putstr("usage: ");
    ft_putstr(program_name);
    ft_putstr(" [-c #][file...]\n");
}