extern void putchar(char c);
extern void printLine(int width, char first, char inner, char final);

void rush(int x, int y)
{
	int currentColumnCount = 0;

	while (currentColumnCount++ < y)
	{
		if (currentColumnCount == 1)
			printLine(x, 'A', 'B', 'C');
		else if (currentColumnCount == y)
			printLine(x, 'C', 'B', 'A');
		else
			printLine(x, 'B', ' ', 'B');
	}
}

void printLine(int width, char first, char inner, char final)
{	
	int currentRowCount = 0;
  
        while (currentRowCount++ < width)
        {
		if (currentRowCount == 1)
                       putchar(first);
                else if (currentRowCount == width)
                       putchar(final);
                else
                       putchar(inner);
 
         }
         putchar('\n');
}



