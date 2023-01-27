int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_atoi(char *str, char *base, int size)
{
	int	sign;
	int	ret;
	int	i;
	int	ind;

	sign = 1;
	ret = 0;
	i = 0;
	ind = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		ind = ft_index(str[i], base);
		ret = ret * size + ind;
		i++;
	}
	return (ret * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	size;

	size = ft_check(base);
	if (size > 1)
		return (ft_atoi(str, base, size));
	return (0);
}
