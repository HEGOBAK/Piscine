#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *p;
    
    while (begin_list)
    {
        p = begin_list;
        begin_list = p->next;
        free_fct(p->data)
        free(p);
    }
}