int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i = 0;

	while (s1[i] == s2[i] && n > 0 && (s1 || s2))
		i++;
	return (s1[i] - s2[i]);
}
