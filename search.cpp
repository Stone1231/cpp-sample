#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void string_searching(string* t, string* p)
{
    // 採用窮舉法，讓P對準T的各個位置
    for (int i = 0; i < (*t).size(); ++i)
    {
        // P不會超出T右端
        if (i + (*p).size() > (*t).size())
            break;

        // 逐一比對每個字元、判斷一不一樣
        bool find = true;
        for (int j = 0; j < (*p).size(); ++j)
            if ((*t)[i + j] != (*p)[j])
            {
                find = false;
                break;
            }

        if (find)
            cout << "T的第" << i << "個字元開始為P"
                 << "\n";
    }    
}

// p[0...i] 的「次長的相同前綴後綴」是 p[0...failure[i]]。
// failure[] 值為 -1 時，代表「次長的相同前綴後綴」為空字串。
int failure[100];
void set_failure(string &p)
{
    for (int i = 1, j = failure[0] = -1; i < p.size(); ++i)
    {
        while (j >= 0 && p[j + 1] != p[i])
            j = failure[j];

        if (p[j + 1] == p[i])
            j++;

        failure[i] = j;
    }

    for (int i = 0; i < p.size(); ++i)
    {
        cout << failure[i] << "\n";
    }
}

void morris_pratt(string& t, string& p)
{
    memset(failure, -1, sizeof(failure));
    if (p.size() > t.size()) return;
 
    // 預先計算 P 的 failure function，O(P)。
    for (int i=1, j=failure[0]=-1; i<p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }
 
    // 進行字串搜尋，O(T)。
    for (int i=0, j=-1; i<t.size(); ++i)
//  for (int i=0, j=-1; i-j-1+p.size()<=t.size(); ++i)
    {
        // 先試 p[0...j] 的「最長的相同前綴後綴」，
        // 再試「次長的相同前綴後綴」，
        // 再試「次次長的相同前綴後綴」……
        // 直到試成功為止。
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];
 
        // t[i] 終於有用處了，終於可以加長！
        if (p[j+1] == t[i]) j++;
 
        // 搜尋到P！
        if (j == p.size()-1)
        {
            cout << "P出現位置" << i - p.size() + 1 << "\n";
 
            // 如果字串結尾不是'\0'的時候，就必須挪動 P。
            // 如果字串結尾是'\0'的時候，就能省略這一行。
            j = failure[j];
        }
    }
}

void chars(){
    string ss = "01234abczABCZ";
    
    char* c = &ss[0];
    for (; *c; ++c)
    {
        cout << *c << "-" << 0 + *c << "\n";
    }
}

int main(int argc, char const *argv[])
{
    string T = "113113211131132";
    string P = "11311";

    string* t = new string;
    string* p = new string;
    *t = T;
    *p = P;

    string_searching(t, p);
    string_searching(&T, &P);

    morris_pratt(*t,*p);
    morris_pratt(T, P);

    set_failure(P); 

    chars();

    system("pause");

    return 0;
}
