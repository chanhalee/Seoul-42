#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	int num;
	int prime;
	int sub;
	
	num = 0;
	prime = 1;
	if(argc == 2)
	{
		sub = atoi(argv[1]);
		if (sub == 1)
			printf("1");
		if (sub < 0)
		{
			if (sub == -2147483648)
			{
				printf("-2147483648\n");
				return (0);
			}
			else{
				printf("-1");
				sub = sub * -1;
				num = 1;
			}
		}
		while (sub > 1 && ++prime)
		{
			while (sub % prime == 0)
			{
				if(num)
					printf("*");
				printf("%d", prime);
				num = 1;
				sub = sub / prime;
			}
		}
	}
	printf("\n");
}
