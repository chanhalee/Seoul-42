void subRush(int a, int flag2);
void putchar(char c);

void rush(int x, int y){
	int flag1;
	flag1 = 1;
	if(x != 0){
		while(y-1 > 0){
			subRush(x, flag1);
			flag1 = 2;
			y--;
		}
		subRush(x, 3);
	}
}

void subRush(int a, int flag2){
	char tempA;
	char tempB;
	char tempC;
	int flag1;
	flag1 = 1;
	if(a >0){

		if(flag2 == 1){
			tempA = 'o';
			tempB = '-';
			tempC = 'o';
		}else if(flag2 == 2){
			tempA = '|';
			tempB = ' ';
			tempC = '|';
		}else{
			tempA = 'o';
			tempB = '-';
			tempC = 'o';
		}
		//if-else
		
		while(a-1  > 0){

			if(flag1){
				putchar(tempA);
				flag1 = 0;
				continue;
			}//if

			putchar(tempB);
			a--;
		}//whiel

		putchar(tempC);
		putchar('\n');
	}
}


