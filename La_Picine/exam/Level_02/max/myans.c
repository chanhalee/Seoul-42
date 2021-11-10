int	max(int* tab, unsigned int len)
{
	unsigned int i;
	int rarge;
	i = -1;
	rarge = 0;
	while (++i < len)
		if(rarge < tab[i])
			rarge = tab[i];
	return (rarge);
}
