#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void intSample(){
    const int length = 10;
    int ints[length];
    int count = sizeof(ints) / sizeof(int);
    int *int_points[length], *pf, *pb, **ppf, **ppb;
    int *int_point = ints;

    for (int i = 0; i < length; ++i)
    {
        ints[i] = i;
        int_points[i] = &ints[i];
    }

    cout << "ints[]\n";
    for (int i = 0; i < length; ++i)
    {
        cout << ints[i] << "\n";
    }
    cout << "\n";

    pf = ints;//同 &ints[0] 
    pb = &ints[length - 1];
    cout << "while pf-ints\n";
    while (pf && pf <= pb)
    {
        cout << pf << " " << *pf << "\n";
        pf++;
    }
    cout << "\n";

    pf = int_points[1] - 1; //int_points[0]不行??
    pb = int_points[length - 1];
    cout << "while pf-int_points\n";
    while (pf && pf <= pb)
    {
        cout << pf << " " << *pf << "\n";
        pf++;
    }
    cout << "\n";

    ppf = int_points;//同 &int_points[0];
    ppb = &int_points[length - 1];
    cout << "while ppf int\n";
    while (*ppf && ppf <= ppb)
    {
        printf(" %d %d %d ",ppf,*ppf,**ppf);
        cout << ppf << " " << *ppf << " " << **ppf << "\n";
        *ppf++;//ppf會變
    }
    cout << "\n";

    ppf = int_points;
    int step = 2;
    cout << "for step ppf int\n";
    for (int i = 0; i < (length / step); ++i)
    {
        cout << ppf << " " << *ppf << " " << **ppf << "\n";
        *ppf += step;//ppf不會變
    }
    cout << "\n";

    cout << "siz of int " << sizeof(int) << "\n";
    cout << "size of int[" << length << "] " << sizeof(ints) << "\n";
    cout << "count of int[" << length << "] " << count << "\n";
    cout << "siz of *int " << sizeof(int_point) << "\n";
    cout << "siz of *int[" << length << "] " << sizeof(int_points) << "\n";
}

void charSample(){
    char chars[] = "ABCDEFGHIJ";
    int count = sizeof(chars) / sizeof(char);
    char *char_points[count], *pf, *pb, **ppf, **ppb;
    char *char_point = chars;
    for (int i = 0; i < count; ++i)
    {
        char_points[i] = &chars[i];
    }

    cout << "chars[]\n";
    for (int i = 0; i < count; ++i)
    {
        cout << chars[i] << "\n";
    }
    cout << "\n";

    pf = chars;//同 &ints[0] 
    pb = &chars[count - 1];
    cout << "while pf-chars\n";
    while (pf && pf <= pb)
    {
        cout << pf << " " << *pf << "\n";
        pf++;
    }
    cout << "\n";

    pf = char_points[0]; //char_points[0]不行??
    pb = char_points[count - 1];
    cout << "while pf-char_points\n";
    while (pf && pf <= pb)
    {
        cout << pf << " " << *pf << "\n";
        pf++;
    }
    cout << "\n";

    ppf = char_points;//同 &char_points[0];
    ppb = &char_points[count - 1];
    cout << "while ppf char\n";
    while (*ppf && ppf <= ppb)
    {
        printf(" %d %d %d ", ppf, *ppf, **ppf);
        cout << ppf << " " << *ppf << " " << **ppf << "\n";
        *ppf++;
    }    
    cout << "\n";

    ppf = char_points;
    int step = 2;
    cout << "for step ppf char\n";
    for (int i = 0; i < (count / step); ++i)
    {
        cout << ppf << " " << *ppf << " " << **ppf << "\n";
        *ppf += step;
    }    
    cout << "\n";

    cout << "siz of char " << sizeof(char) << "\n";
    cout << "siz of char[] " << sizeof(chars) << "\n";    
    cout << "count of char[] " << count << "\n";
    cout << "siz of *char " << sizeof(char_point) << "\n";
    cout << "siz of *char[" << count << "] " << sizeof(char_points) << "\n";


}

void stringSample(){
    const int length = 10;
    string strings[length];
    int count = sizeof(strings) / sizeof(string);
    string *string_points[length], *pf, *pb, **ppf, **ppb;
    string *string_point = strings;

    //string strings[100];
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j <= i; ++j){
            strings[i] += to_string(i);
        }
        //strings[i] = to_string(i) + ".hello world";
        string_points[i] = &strings[i];
    }

    cout << "strings[]\n";
    for (int i = 0; i < length; ++i)
    {
        cout << strings[i] << "\n";
    }
    cout << "\n";

    pf = strings;//同 &ints[0] 
    pb = &strings[length - 1];
    cout << "while pf-strings\n";
    while (pf && pf <= pb)
    {
        cout << pf << " " << *pf << "\n";
        pf++;
    }
    cout << "\n";    

    pf = string_points[0];
    pb = string_points[length - 1];
    cout << "while pf-string_points\n";
    while (pf && pf <= pb)
    {
        cout << pf << " " << *pf << "\n";
        pf++;
    }
    cout << "\n";    

    ppf = string_points;//同 &string_points[0];
    ppb = &string_points[length - 1];
    cout << "while ppf string\n";
    while (*ppf && ppf <= ppb)
    {
        printf(" %d %d %d ",ppf,*ppf,**ppf);
        cout << ppf << " " << *ppf << " " << **ppf << "\n";
        *ppf++;//ppf會變
    }
    cout << "\n";

    ppf = string_points;
    int step = 2;
    cout << "for step ppf string\n";
    for (int i = 0; i < (length / step); ++i)
    {
        cout << ppf << " " << *ppf << " " << **ppf << "\n";
        *ppf += step;//ppf不會變
    }
    cout << "\n";

    cout << "siz of string " << sizeof(string) << "\n";
    cout << "siz of strings[" << length << "] " << sizeof(strings) << "\n";
    cout << "count of string[" << length << "] " << count << "\n";
    cout << "siz of *string " << sizeof(string_point) << "\n";
    cout << "siz of *string[" << length << "] " << sizeof(string_points) << "\n";    
}

int main()
{
    intSample();

    charSample();

    stringSample();

    system("pause");
}