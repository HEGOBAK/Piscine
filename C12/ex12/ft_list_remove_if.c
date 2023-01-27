#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)(), void (*free_fct)(void *))
{
    t_list *prev;
    t_list *current;
    t_list *next;

    prev = 0;
    current = *begin_list;
    while (current)
    {
        next = current->next;
        if (!cmp(current->data, data_ref))
        {
            free_fct(current->data);
            if (current == *begin_list)
                *begin_list = next;
            free(current);
            if (prev)
                prev->next = next;
        }
        else
            prev = current;
        current = next;
    }
}