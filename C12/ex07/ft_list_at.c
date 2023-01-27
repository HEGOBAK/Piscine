#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int i;

    i = 0;
    while (i++ < nbr)
    {
        if (!begin_list)
            break;
        begin_list = begin_list->next;
    }
    return (begin_list);
}