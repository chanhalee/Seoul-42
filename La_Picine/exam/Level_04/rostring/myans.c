#include <unistd.h>
#include <stdlib.h>
int isitspace(char c)
{
	if(c == ' '||c == '\t')
		return 1;
	return 0;
}
int main(int argc, char **argv)
{
	int index;
	int flag = 1;
	index = -1;
	int index2 = -1;
	char store[500];
	if(argc >= 2)
	{
		while (argv[1][++index])
		{
			if (isitspace(argv[1][index]))
				continue ;
			if(flag)
			{
				while (!isitspace(argv[1][index])&&!argv[1][index])
					store[++index2] = argv[1][index++];
				store[++index2] = '\0';
				flag = 0;
				continue ;
			}
			if(argv[1][index])
			{
				while(!isitspace(argv[1][index])&&!argv[1][index])
					write(1, &argv[1][index++], 1);
				write(1, " ", 1);
			}
		}
	}
	write(1, store, index2);
	write(1, "\n", 1);
}

