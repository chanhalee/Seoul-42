#include <unistd.h>

int	    is_power_of_2(unsigned int n)
{
	unsigned int next;

	next = n;
	if(n == 0)
		return (0);
	if(n == 1)
		return (1);
	while(next != 2)
	{
		if (next != (next / 2) * 2)
			return (0);
		next = next / 2;
	}
	return (1);
}

int main (void)
{
	if (is_power_of_2(4))
		write(1, "ok", 2);
	else
		write(1, "no", 2);
	write(1, "\n", 1);
	return 0;
}
