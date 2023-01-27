int ft_tabsize(char **tab)
{
    int i;

    i = 0;
    while (*tab++)
        i++;
    return (i);
}

void ft_swap(char **a, char **b)
{
    char *temp;
    temp = *a;
    *a = *b;
    *b = temp;   
}

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
    int counter;
    int size;
    int i;

    i = 0;
    size = ft_tabsize(tab);
    while (i < size - 1)
    {
        counter = 0;
        while (counter < size -i -1)
        {
            if (cmp(tab[counter], tab[counter + 1]) > 0)
                ft_swap(&tab[counter], &tab[counter + 1]);
            counter++;
        }
        i++;
    }    
}