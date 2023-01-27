void ft_sort_int_tab(int *tab, int size)
{
	int i = 0;

	while (size - 1 > 0)
	{
		int x = i + 1;
		int tempsize = size - 1;
		while (tempsize > 0)
		{
			if (tab[i] > tab[x])
			{
				int temp = tab[i];
				tab[i] = tab[x];
				tab[x] = temp;
			}
			x++;
			tempsize--;
		}
		i++;
		size--;
	}
}
