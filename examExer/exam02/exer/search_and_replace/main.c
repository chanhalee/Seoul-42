#include <unistd.h>
#include <stdlib.h>

int valid_check(int argc, char **argv);

int main(int argc, char **argv)
{
	int tempa;

	tempa = -1;
	if (!valid_check(argc, argv))
		return 0;
	while (argv[1][++tempa])
	{
		if (argv[1][tempa] == argv[2][0])
			write(1, argv[3], 1);
		else
			write(1, &argv[1][tempa], 1);
	}
	write(1, "\n", 1);
	return (0);


}

int valid_check(int argc, char **argv)
{
	int tempa;

	tempa = 0;
	if(argc != 4)
	{
		write( 1, "\n", 1);
		return 0;
	}
	if (argv[2][0] != 0 && argv[3][0] != 0
		&& argv[2][1] == 0 && argv[3][1] == 0)
		return 1;
	write(1, "\n", 1);
	return 0;
}
