#include <string>
#include <stdio.h>
#include "stdafx.h"
using namespace std;
int fun(char *, char *, int);
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("source.txt", "r");
    fseek(fp, 0, SEEK_END);
    int siz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *a = new char[siz + 1];
    fread(a, siz, 1, fp);
    a[siz] = 0;
    fclose(fp);
    char b[] = "qwertyuiop";
    char c[] = "asdfghjkl";
    char d[] = "zxcvbn";
    char e[] = "qwertyuioasdfghjkzxcvbnqpwertyuioasdfghjkzxcvbn";
    char f[] = "qwerltyuioasdfghjkzxcvbnqwertyuioasdfghjkzxcvbn";
    char g[] = "qwertyuioasdfghjkzxcvbnqwertyuiomasdfghjkzxcvbn";
    char h[] = "pwertyuioasdfghjkzxcvbn";
    char j[] = "plmmlp";
    char k[] = "qmlp";
    for (int i = 0; i < 30; i++)
    {
        //	cout <<fun(a,b,siz)<<"\n";
        //	cout <<fun(a,c,siz)<<"\n";
        //	cout <<fun(a,d,siz)<<"\n";
        //	cout <<fun(a,e,siz)<<"\n";
        //	cout <<fun(a,f,siz)<<"\n";
        //	cout <<fun(a,g,siz)<<"\n";
        //	cout <<fun(a,h,siz)<<"\n";
        cout << fun(a, k, siz) << "\n";
    }
    delete[] a;
    system("PAUSE");
    return 0;
}
int fun(char *a, char *b, int ien)
{
    int cnt = 0;
    int jen = sizeof(b);
    int i;
    for (i = 0; i < ien; i++)
    {
        if (a[i] == b[0])
        {
            int pc = 0;
            while (a[i + pc] == b[pc] && pc < jen)
            {
                ++pc;
                if (pc == jen)
                    ++cnt;
            }
        }
    }
    return cnt;
}