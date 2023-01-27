#include "ft_list.h"

int ft_size_list(t_list *begin_list)
{
    int i;

    i = 0;
    while (begin_list)
    {
        i++;
        begin_list = begin_list->next;
    }
    return (i);
}

t_list *ft_list_location(t_list *begin_list, int i)
{
    int x;

    x = 0;
    while (x < i)
    {
        if (!begin_list)
            break;
        begin_list = begin_list->next;
    }
    return (begin_list);
}

void ft_swap(*current, *previous, *next)
{
    t_list *temp;

    temp = next->next;
    if (previous)
        previous->next = next;
    next->next = current;
    current->next = temp;
}

void    compare(t_list **begin_list, int j, int(cmp)())
{
    t_list *previous;
    t_list *current;
    t_list *next;

    if (j > 0)
        previous = ft_list_location(*begin_list, j - 1);
    else
        previous = 0;
    current = ft_list_location(*begin_list, j);
    next = ft_list_location(*begin_list, j + 1);
    if (cmp(current->data, next->data) >= 0)
        ft_swap(curent, previous, next);
}

void ft_list_sort(t_list **begin_list, int(*cmp)())
{
    int i;
    int j;
    int size;

    i = 0;
    size = ft_size_list(*begin_list);
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            compare(begin_list, j, cmp);
            j++;
        }
        i++;
    }
}