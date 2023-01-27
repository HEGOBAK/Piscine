int ft_atoi(char *str)
{
	int i = 0;
	long result = 0;
	int sign = 1;

	while ((!(str[i] >= '0' && str[i] <= '9')) || (str[i] == '+' || str[i] == '-') )
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result += str[i] - '0';
		result *= 10;
		i++;
	}
	result /= 10;
	return (result * sign);
}

/*#include <stdio.h>
int main()
{
	printf ("%d", ft_atoi("   -+---21223"));
	return 0;
}*/
