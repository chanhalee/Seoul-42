//
// Created by Lee ChanHa on 2021/09/18.
//

#ifndef RUSH_01_SUBCASES_H
#define RUSH_01_SUBCASES_H
///col을 reverse 해제하여 straight 기준으로 보내줘야 함. (int)1.5 + type*0.5
///a = casenumber b = col
//int fourOneSub(int a, int b); //케이스 1234 1개라 없어도 됨
int threeTwoSub(int a, int b);
int threeOneSub(int a, int b);
int twoTwoSub(int a, int b);
int twoOneSub(int a, int b);


//int fourOneSub(int a, int b)
//{
//
//}

//{1, 2, 4, 3};
//{1, 3, 4, 2};
//{2, 3, 4, 1};
int threeTwoSub(int a, int b)
{
    if(b == 2)
        return 4;
    if(b == 0)
        if(a == 0||a==1)
            return (1);
        else
            return (2);
    if(b == 1)
        if(a == 0)
            return (2);
        else
            return (3);
    return (3 - a); //막 레인
}
//1, 3, 2, 4
//2, 1, 3, 4
//2, 3, 1, 4
int threeOneSub(int a, int b)
{
    if(b == 3)
        return (4);
    if(b == 1 && (a == 0 || a == 2))
        return (3);
    if(b == 2 && a == 1)
        return (3);
    if(b == 1 && (a == 1 || a == 2))
        return (2);
    if(b == 2 && a == 0)
        return (2);
    return (1);
}
//1, 4, 2, 3
//2, 4, 1, 3
//3, 4, 1, 2
//3, 2, 4, 1
//3, 1, 4, 2
//2, 1, 4, 3
int twoTwoSub(int a, int b)
{
    if((b==1 && (a < 5 && a > 1)) || (b==3 && !(a < 5 && a > 1)))// 길면 2개로 나눌 것.
        return (3);
    if((b == 1 && a < 3) || (b == 2 && a >2))
        return (4);
    if((b == 0 && a == 0) || (b == 3 && a == 3))
        return (1);
    if(b == 1 && (a == 4 || a == 5))
        return (1);
    if(b == 2 && (a == 1 || a == 2))
        return (1);
    return (2);
}
//3, 1, 2, 4
//3, 2, 1, 4
int twoOneSub(int a, int b)
{
    if(b == 0)
        return (3);
    if(b == 3)
        return (4);
    if(a + b == 2)
        return (2);
    return (1);
}

#endif //RUSH_01_SUBCASES_H
