int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void ft_swap(char **a, char **b)
{
    char *temp;
    temp = *a;
    *a = *b;
    *b = temp;   
}

int ft_tabsize(char **tab)
{
    int i;

    i = 0;
    while (*tab++)
        i++;
    return (i);
}

void ft_sort_string_tab(char **tab)
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
            if (ft_strcmp(tab[counter], tab[counter + 1]) > 0)
                ft_swap(&tab[counter], &tab[counter + 1]);
            counter++;
        }
        i++;
    }
}