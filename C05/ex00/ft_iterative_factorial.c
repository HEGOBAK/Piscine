int ft_iterative_factorial(int nb)
{
	int result = 1;

	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	while (nb > 0)
		result *= nb--;
	return (result);
}
