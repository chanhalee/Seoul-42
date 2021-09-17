#include <stdio.h>
#include <stdlib.h>
extern int proceed(int line, int **arr, int **sight);

int **parse_input(char *str);
const int SIZE = 4;
int main(int argc, char** argv) {
    int **sight;
    int **result;
    int counter1;

    result = (int **)malloc(SIZE * sizeof(int *));
    counter1 = 0;
    while(counter1 < SIZE)
        result[counter1++] = (int *)malloc(SIZE * sizeof(int));
    sight = parse_input(argv[1]);
    proceed(0, result, sight);

    // write()로 result 출력 구현
    return 0;
}

int **parse_input(char *str){   //길이검사 추가
    int counter1;
    int counter2;
    int** result;

    result = (int **)malloc(SIZE * sizeof(int *));
    counter1 = 0;
    while(counter1 < SIZE)
        result[counter1++] = (int *)malloc(SIZE * sizeof(int));
    counter1 = -1;
    counter2 = -1;
    while(++counter1 < SIZE){
        while(++counter2 < SIZE)
            if(str[(counter1*4+counter2)*2]<'1' || str[(counter1*4+counter2)*2]>'0'+SIZE)
                return NULL;
            else
                result[counter1][counter2] = (int)(str[(counter1*4+counter2)*2]-'0');
    }
    return (result);
}



