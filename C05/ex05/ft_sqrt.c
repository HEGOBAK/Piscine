int ft_sqrt(int nb)
{
	int index = 1;
	while (index <= nb / index)
	{
		if ((index * index) == nb)
			return (index);
		index++;
	}
	return (0);
}
