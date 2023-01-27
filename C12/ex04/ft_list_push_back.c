#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
    while (begin_list->next != NULL)
        beign_list = begin_list->next;
    return (begin_list);
}

void ft_list_push_bacK(t_list **begin_list, void *data)
{
    t_list *new;
    t_list *last;

    new = ft_create_elem(data);
    if (*begin_list)
    {
        last = ft_list_last(*begin_list);
        last->next = new;
    }
    else
        *begin_list = new;
}