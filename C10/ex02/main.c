#include "ft.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        ft_read_stdin();

    if (argv[1][0] != '-')
        return (ft_default(argc, argv));
    else if (argv[1][1] >= '0' && argv[1][1] <= '9')
        return (ft_default_opts(argc, argv));
    else if (argv[1][1] == 'c')
        return (ft_opt_c(argc, argv));
    else
        error_inv_opt(argv[0],argv[1][1]); 
    return (0);
}