#include <stdlib.h>
#include "ft_stock_str.h"

int ft_strlen(char *str)
{
	int i;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int i = 0;
	char *dest;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (0);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int i;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);

	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
