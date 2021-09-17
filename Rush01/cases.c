//
// Created by Lee ChanHa on 2021/09/18.
//
///line은 일상에서 통상적으로 쓰는 1234가 아닌 배열인덱스 0123사용
#include "subcases.h"

const int STRAIGHT = 1;
const int REVERSE = -1;
int fourOne(int type,  int line, int **arr, int **sight);
int threeTwo(int type,  int line, int **arr, int **sight);
int threeOne(int type,  int line, int **arr, int **sight);
int twoTwo(int line, int **arr, int **sight);
int twoOne(int type,  int line, int **arr, int **sight);
int proceed(int line, int **arr, int **sight);

int proceed(int line, int **arr, int **sight)
{
    if(line < 4)
    {
        // 관찰 결과 분석하여 각 케이스에 맞는 실행 반환값이 1일경우 1 반환 후 종료 아닐경우 0 반환후 종료
        //return(function(-------))으로 라인 다이어트.
    }
        //line에 4를 전달받았을 경우 검사 실시 , pass는 1을 fail은 0를 반환, 반환값 반환
}

int fourOne(int type,  int line, int **arr, int **sight) // only one case 1234
{
    int col;
    int newcol;

    col = -1;
    while (++col < 4)
    {
        newcol = col;
        if (type == REVERSE)
            newcol = 3 - col;
        arr[line][col] = newcol + 1;
    }
    if(proceed(line+1, arr, sight))
        return (1);
    else
        return (0);
}

int threeTwo(int type, int line, int **arr, int **sight)
{
    int subzcase;
    int col;
    int newcol;

    subzcase = -1;
    while(++subzcase < 3)//3-2의 서브케이스 종류는 3가지
    {
        col = -1;
        while(++col < 4)
        {
            newcol = col;
            if(type == REVERSE)
                newcol = 3 - col;
            arr[line][col] = threeTwoSub(subzcase, newcol);
        }
        if(proceed(line+1, arr, sight))
            return (1);
    }
    return (0);
}

int threeOne(int type,  int line, int **arr, int **sight)
{
    int subzcase;
    int col;
    int newcol;

    subzcase = -1;
    while(++subzcase < 2)//2-1의 서브케이스 종류는 2가지
    {
        col = -1;
        while(++col < 4)
        {
            newcol = col;
            if(type == REVERSE)
                newcol = 3 - col;
            arr[line][col] = threeOneSub(subzcase, newcol);
        }
        if(proceed(line+1, arr, sight))
            return (1);
    }
    return (0);
}

int twoTwo(int line, int **arr, int **sight) ///타입은 항상 straight 앞뒤 무관
{
    int subzcase;
    int col;

    subzcase = -1;
    while(++subzcase < 6)//2-2의 서브케이스 종류는 6가지
    {
        col = -1;
        while(++col < 4)
        {
            arr[line][col] = twoTwoSub(subzcase, col);
        }
        if(proceed(line+1, arr, sight))
            return (1);
    }
    return (0);
}

int twoOne(int type,  int line, int **arr, int **sight)
{
    int subzcase;
    int col;
    int newcol;

    subzcase = -1;
    while(++subzcase < 2)//2-1의 서브케이스 종류는 2가지
    {
        col = -1;
        while(++col < 4)
        {
            newcol = col;
            if(type == REVERSE)
                newcol = 3 - col;
            arr[line][col] = twoOneSub(subzcase, newcol);
        }
        if(proceed(line+1, arr, sight))
            return (1);
    }
    return (0);
}