#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{   
    int *root = 0;
    int ints[100];
    int ints_count = sizeof(ints) / sizeof(int);
    int* int_points[100], **qf, **qb;
    //int* int_point;
    int* int_point = ints;

    for (int i=0; i<ints_count; ++i)
    {
        *int_points[i] = i;
    }

    qf = qb = int_points;
    *qb += (root * 99);
    //*qb++ = root;//下一個指標重新指到root
    //cout << "root " << root;

    while (qf <= qb)
    {
        cout << "**qf " << **qf;
        *qf++;
        //*qb++;
    }

    cout << "siz of int " << sizeof(int) << "\n";
    cout << "size of int[100] " << sizeof(ints) << "\n";
    cout << "count of int[100] " << ints_count << "\n";
    cout << "siz of *int " << sizeof(int_point) << "\n";
    cout << "siz of *int[100] " << sizeof(int_points) << "\n";

    for (int i=0; i<ints_count; ++i)
    {
        cout << ints[i] << "\n";
    }


    char chars[100];
    cout << "siz of char " << sizeof(char) << "\n";
    cout << "siz of char[100] " << sizeof(chars) << "\n";
    
    string strings[100];

    cout << "siz of string " << sizeof(string) << "\n";
    cout << "siz of strings[100] " << sizeof(strings) << "\n";




    //int* q[100], **qf, **qb;

    // memset(q, 1, sizeof(q));

    // for(size_t i = 0; i < 100; i++)
    // {
    //     cout << *(q[i]);
    // }
    

    // int* root = q[0];
    // qf = qb = q;
    // *qb++ = root;

    // while (qf < qb)
    // {
    //     int* p = *qf++;

    //     //*qb++ = p->l[i];
    // }
    system("pause");
}    