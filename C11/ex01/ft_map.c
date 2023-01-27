#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
    int *res;
    int  i;

    res = malloc(sizeof(int) * length);
    i = -1;
    while (++i < length)
        res[i] = (*f)(tab[i]);
    return (res);
}