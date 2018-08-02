// kx.cpp : 定義主控台應用程式的進入點。
#include "stdafx.h"
#include "kxheap.h"
#include <string>
//#define ee 10
using namespace std;
using namespace kxlib;
int main(int argc, char const *argv[])
{
    int a[] = {2, 3, 5, 1, 7, 8, 6};
    char c[] = "zwxyacb";
    //int z=1;
    //z=z>>1;
    //cout <<z<<"\n";
    size_t i;
    size_t b = sizeof c;
    kxMaxHeap<char> bb(b);
    bb.Push(c, b);
    bb.MakeHeap();
    bb.Sort();
    kxMaxHeap<int> aa(7);
    aa.Push(a, 7);
    aa.MakeHeap();
    aa.Sort();
    for (i = 1; i < 8; i++)
        cout << aa.operator[](i) << "\n";
    for (i = 2; i < (b + 1); i++)
        cout << bb.operator[](i) << "\n";
    //cout << <<"\n";

    system("PAUSE");
    return 0;
}