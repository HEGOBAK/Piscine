#include <stdlib.h>

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

int ft_reslen(int nbr, int baselen, int sign)
{
	int count = 0;

	if (sign == -1)
		count++;

	while (nbr > 0)
	{
		nbr /= baselen;
		count++;
	}
	return (count);
}

char *ft_revstr(char *str, int strlen, int sign)
{
	char *final;
	int i = 0;

	final = (char *)malloc(sizeof(char) * strlen);
	if (final == NULL)
		return (0);

	if (sign == -1)
		i = 1;
	
	if (sign == -1 && strlen == 3)
		return (str);

	while (i < strlen - 1)
	{
		final[i] = str[strlen - i - 2];
		i++;
	}
	final[i] = '\0';
	return (final);
}

char *ft_convert(int nbr, char *base, int baselen)
{
	char *res;
	int sign = 1;
	if (nbr < 0)
	{
		sign = -1;
		nbr *= -1;
	}
	int size_res = ft_reslen(nbr, baselen, sign) + 1;

	res = (char *)malloc(sizeof(char) * size_res);
	if (res == NULL)
		return (0);

	int i = 0;
	if (sign == -1)
		res[i++] = '-';
	while (i < size_res - 1)
	{
		res[i++] = base[nbr % baselen];
		nbr /= baselen;
	}
	res[i] = '\0';
	return (ft_revstr(res, size_res, sign));
}

char *ft_itoa_base(int nbr, char *base)
{
	int size;

	size = ft_check(base);
	if (size > 1)
		return (ft_convert(nbr, base, size));
	return (0);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int intval = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(intval, base_to));
}

/*#include <stdio.h>
int main()
{
	char *result = ft_convert_base("1100", "01", "0123456789");
	printf ("%s", result);
	free(result);
	return (0);
}*/
