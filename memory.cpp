#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void intSample()
{
    int i1 = 1;
    int i2 = 2;
    int i3 = 3;

    int arr[100];

    int in = 101;

    int *p1 = &i1;
    int **pp1 = &p1;

    int *p2 = &i2;
    int **pp2 = &p2;

    int *p3 = &i3;
    int **pp3 = &p3;

    int *pn = &in;
    int **ppn = &pn;

    printf(" %d %d %d ", pp1, *pp1, **pp1);
    cout << pp1 << " " << *pp1 << " " << **pp1 << "\n";

    printf(" %d %d %d ", pp2, *pp2, **pp2);
    cout << pp2 << " " << *pp2 << " " << **pp2 << "\n";

    printf(" %d %d %d ", pp3, *pp3, **pp3);
    cout << pp3 << " " << *pp3 << " " << **pp3 << "\n";

    printf(" %d %d %d ", ppn, *ppn, **ppn);
    cout << ppn << " " << *ppn << " " << **ppn << "\n";

    printf("unit pp %d %d %d \n", pp1 - pp2, pp2 - pp3, pp3 - ppn);
    printf("      p %d %d %d \n", *pp1 - *pp2, *pp2 - *pp3, *pp3 - *ppn);
    printf("      p item %d \n", &arr[1] - &arr[0]);

    printf("10   pp %d %d %d \n", (int)pp1 - (int)pp2, (int)pp2 - (int)pp3, (int)pp3 - (int)ppn);
    printf("      p %d %d %d \n", (int)*pp1 - (int)*pp2, (int)*pp2 - (int)*pp3, (int)*pp3 - (int)*ppn);
    printf("      p item %d \n", (int)&arr[1] - (int)&arr[0]);
}

template <typename T, size_t N>
void templateSample(T &i1, T &i2, T &i3,T (&arr)[N], T &in)
{
    T *p1 = &i1;
    T **pp1 = &p1;

    T *p2 = &i2;
    T **pp2 = &p2;

    T *p3 = &i3;
    T **pp3 = &p3;

    //T arr[100];

    T *pn = &in;
    T **ppn = &pn;

    printf("%d %d %d ", pp1, *pp1, **pp1);
    cout << pp1 << " " << *pp1 << " " << **pp1 << " \n";

    printf("%d %d %d ", pp2, *pp2, **pp2);
    cout << pp2 << " " << *pp2 << " " << **pp2 << " \n";

    printf("%d %d %d ", pp3, *pp3, **pp3);
    cout << pp3 << " " << *pp3 << " " << **pp3 << " \n";

    printf("%d %d %d ", ppn, *ppn, **ppn);
    cout << ppn << " " << *ppn << " " << **ppn << " \n";

    printf("\nunit \n");
    printf("pp %d %d %d \n", pp1 - pp2, pp2 - pp3, pp3 - ppn);
    printf("p %d %d %d \n", *pp1 - *pp2, *pp2 - *pp3, *pp3 - *ppn);
    printf("p item %d \n", &arr[1] - &arr[0]);

    printf("\nbyte \n");
    printf("pp %d %d %d \n", (int)pp1 - (int)pp2, (int)pp2 - (int)pp3, (int)pp3 - (int)ppn);
    printf("p %d %d %d \n", (int)*pp1 - (int)*pp2, (int)*pp2 - (int)*pp3, (int)*pp3 - (int)*ppn);
    printf("p item %d \n", (int)&arr[1] - (int)&arr[0]);
    cout << "\n";
}

int main()
{
    //intSample();

    int i1 = 4;
    int i2 = 3;
    int i3 = 2;
    int is[100];
    int in = 100;
    templateSample<int>(i1, i2, i3, is, in);
    
    char c1 = 'Z';
    char c2 = 'a';
    char c3 = '1';
    char cs[100];
    char cn = 'g';
    templateSample<char>(c1, c2, c3, cs, cn);

    string s1 = "Z";
    string s2 = "a";
    string s3 = "1";
    string ss[100];
    string sn = "g";
    templateSample<string>(s1, s2, s3, ss, sn);

    system("pause");
}