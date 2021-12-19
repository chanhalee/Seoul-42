#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "/Users/lch/42Seoul/Libft/libft.h"

int main(void)
{
	char	s[20] = " 123456789 ";

	printf("%s", ft_strtrim(s,"  \0"));

	return 0;
}

