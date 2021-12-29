#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "/Users/lch/42Seoul/Libft/libft.h"

int main(void)
{
	char	s[200] = " 123423231211aa 1\n567d121as12389 ";
	char	a[10] = "123 ";



	printf("%s", ft_strtrim(s, a));

	return 0;
}

