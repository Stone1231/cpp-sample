#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void string_searching(string* t, string* p)
{
    // �ĥνa�|�k�A��P���T���U�Ӧ�m
    for (int i = 0; i < (*t).size(); ++i)
    {
        // P���|�W�XT�k��
        if (i + (*p).size() > (*t).size())
            break;

        // �v�@���C�Ӧr���B�P�_�@���@��
        bool find = true;
        for (int j = 0; j < (*p).size(); ++j)
            if ((*t)[i + j] != (*p)[j])
            {
                find = false;
                break;
            }

        if (find)
            cout << "T����" << i << "�Ӧr���}�l��P"
                 << "\n";
    }    
}

// p[0...i] ���u�������ۦP�e����v�O p[0...failure[i]]�C
// failure[] �Ȭ� -1 �ɡA�N��u�������ۦP�e����v���Ŧr��C
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
 
    // �w���p�� P �� failure function�AO(P)�C
    for (int i=1, j=failure[0]=-1; i<p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }
 
    // �i��r��j�M�AO(T)�C
    for (int i=0, j=-1; i<t.size(); ++i)
//  for (int i=0, j=-1; i-j-1+p.size()<=t.size(); ++i)
    {
        // ���� p[0...j] ���u�̪����ۦP�e����v�A
        // �A�աu�������ۦP�e����v�A
        // �A�աu���������ۦP�e����v�K�K
        // ����զ��\����C
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];
 
        // t[i] �ש󦳥γB�F�A�ש�i�H�[���I
        if (p[j+1] == t[i]) j++;
 
        // �j�M��P�I
        if (j == p.size()-1)
        {
            cout << "P�X�{��m" << i - p.size() + 1 << "\n";
 
            // �p�G�r�굲�����O'\0'���ɭԡA�N�������� P�C
            // �p�G�r�굲���O'\0'���ɭԡA�N��ٲ��o�@��C
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
