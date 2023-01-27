#include <unistd.h>

int checkbase(char *str, int baselen)
{
	int i = 0;

	if (baselen <= 1)
		return 0;

	while (str[i])
	{
		int j = 1;

		if (str[i] == '+' || str[i] == '-')
			return 0;

		while (j < baselen - i)
		{
			if (str[i] == str[i + j])
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

void ft_convert(int nbr, char *base, int size)
{
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= size)
		ft_convert(nbr / size, base, size);
	write (1, &base[nbr % size], 1);
	
}

void ft_putnbr_base(int nbr, char *base)
{
	int baselen = 0;
	while(base[baselen])
		baselen++;

	if (checkbase(base, baselen))
	{
		ft_convert(nbr, base, baselen);
	}
}

/*int main()
{
	ft_putnbr_base(-50, "01");
	return 0;
}*/
