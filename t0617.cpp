// t0617.cpp : 定義主控台應用程式的進入點。
#include "stdafx.h"
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int Top = 0;
    int i, I;
    int a[] = {1, 4, 7, 8, 2, 5, 6, 3};
    for (i = 0; i < 8; i++)
        cout << a[i] << ',';
    cout << "\n";
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int N = 8;
    int *Slots;
    Slots = new int[9];
    for (I = 0; I < N; ++I)
    {
        int X = ++Top;
        for (; X > 1 && a[I] > Slots[X >> 1]; X >>= 1)
            Slots[X] = Slots[X >> 1];
        Slots[X] = a[I];
    }
    for (i = 1; i < 9; i++)
        cout << Slots[i] << ',';
    cout << "\n";
    //1C~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    for (i = Top << 1; i > 0; --i)
    {
        int C = i << 1;
        int Tmp = Slots[i];
        while (C <= Top)
        {
            if (C < Top && (Slots[C + 1] > Slots[C]))
                ++C;
            if (Slots[C] > Tmp)
                Slots[i] = Slots[C];
            else
                break;
            i = C;
            C = i << 1;
        }
        Slots[i] = Tmp;
    }
    //for ( i = 1; i <9; i++)
    //cout <<Slots[i]<<',';
    //cout <<"\n";
    //2g~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int _Top = Top;
    while (Top > 1)
    {
        int Tmp = Slots[1];
        Slots[1] = Slots[Top];
        --Top;
        //for ( i = 1; i <9; i++)
        //cout <<Slots[i]<<',';
        //cout <<"\n";
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if (Top > 1)
        {
            int X = 1;
            int C = X << 1;
            int Tmp = Slots[X];
            while (C <= Top)
            {
                if (C < Top && (Slots[C + 1] > Slots[C]))
                    ++C;
                if (Slots[C] > Tmp)
                    Slots[X] = Slots[C];
                else
                    break;
                X = C;
                C = X << 1;
            }
            Slots[X] = Tmp;
        }
        Slots[Top + 1] = Tmp;
    }
    Top = _Top;
    for (i = 1; i < 9; i++)
        cout << Slots[i] << ',';
    cout << "\n";
    //3dg~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    delete[] Slots;
    system("PAUSE");
    return 0;
}