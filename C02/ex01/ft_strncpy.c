char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i = 0;
	while (src[i] && n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
