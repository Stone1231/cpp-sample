#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void swap_value(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap_pointer(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

swap_reference(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int g_int = 0;
void changePtr1(int *pInt)
{
    //pInt是localPInt「複製」過來的
    //所以做改變並不會反應到localPInt
    pInt = &g_int;
}
void changePtr2(int **pInt)
{
    //pInt是&localPInt「複製」過來的
    //所以做改變並不會反應到&localPInt 
    //所改變的是pInt所指向的內容
    *pInt = &g_int;
}
void changePtr3(int *&refPInt)
{
    //refPInt與localPInt其實是「同一件東西」
    refPInt = &g_int;
}

int main()
{
    int a, b;
    a = 100;
    b = 200;
    cout << "default val " << a << "," << b << "\n";
    swap_value(a, b);
    cout << "swap_value " << a << "," << b << "\n";
    swap_pointer(&a, &b);
    cout << "swap_pointer " << a << "," << b << "\n";
    swap_reference(a, b);
    cout << "swap_reference " << a << "," << b << "\n";

    int localInt = 1;
    int *localPInt = &localInt;

    printf("default val %d \n", *localPInt);

    changePtr1(localPInt);
    printf("changePtr1 %d \n", *localPInt);

    localInt = 1;
    localPInt = &localInt;
    changePtr2(&localPInt);
    printf("changePtr2 %d \n", *localPInt);

    localInt = 1;
    localPInt = &localInt;
    changePtr3(localPInt);
    printf("changePtr3 %d \n", *localPInt);

    system("pause");
}
