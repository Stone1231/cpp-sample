#include "stdafx.h"
#include "kxheap.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;


int N = 1000;   // P���Ӽ�
char T[100+1];
char P[1000][100+1];
 
bool occur[1000];   // �O���U��P���S���X�{�bT��
int equiv[1000];    // �O���U��P���S�����ƥX�{
int const ASCII_COUNT = 128;

struct TrieNode
{
    TrieNode* l[ASCII_COUNT], *suffix, *dictsuffix;
    int index;  // P���s��
 
    TrieNode()
    {
        memset(l, 0, sizeof(l));
        suffix = 0;
        dictsuffix = 0;
        index = -1;
    }
} *root;
 
// ��l��
void init()
{
    memset(occur, false, sizeof(occur));
    memset(equiv, -1, sizeof(equiv));
    root = new TrieNode();
}
 
// �屼���trie
void free(TrieNode* p = root)
{
    for (int i=0; i<ASCII_COUNT; ++i)
        if (p->l[i])
            free(p->l[i]);
    delete p;
}
 
// ��@�Ӧr��[�Jtrie
void add(char* s, int index)
{
    TrieNode* p = root;
    for (; *s; ++s)
    {
        if (!p->l[*s])
            p->l[*s] = new TrieNode();
            
        p = p->l[*s];
    }
 
    // �p�G���r�ꤧ�e���X�{�A�N�S�O�O���_�ӡC    
    if (p->index == -1)
        p->index = index;
    else
        equiv[index] = p->index;
}
 
// �K�Wsuffix link�Mdictionary suffix link
// �HBFS���Ƕi��
// �ɶ�������O(?(Pi))
void build()
{
    TrieNode* q[100000], **qf, **qb;
    qf = qb = q;
    *qb++ = root;
 
    while (qf < qb)
    {
        TrieNode* p = *qf++;
        for (int i=0; i<ASCII_COUNT; ++i)
            if (p->l[i])
            {
                // �K�W suffix link
                TrieNode* q = p->suffix;
                while (q && !q->l[i]) 
                    q = q->suffix;
                if (q) 
                    p->l[i]->suffix = q->l[i];
                else   
                    p->l[i]->suffix = root;
 
                // �K�W dictionary suffix link
                TrieNode* r = p->l[i]->suffix;
                if (r->index != -1) 
                    p->l[i]->dictsuffix = r;
                else 
                    p->l[i]->dictsuffix = r->dictsuffix;
 
                *qb++ = p->l[i];
            }
    }
}
 
// ��trie�PT�i��r��j�M
// �ɶ�������O(T+K)
void search(char* s)
{
    TrieNode* p = root;
    for (; *s; ++s)
    {
        // ���_���r���A�����令�\�C
        // �������`�p�ɶ������׬�O(T)�C
        while (p && !p->l[*s]) 
            p = p->suffix;

        if (p) 
            p = p->l[*s];
        else 
            p = root;
 
        // ��dictionary suffix link���Ҧ��۲Ū�P�C
        // �������`�p�ɶ������׬�O(K)�C
        for (TrieNode* q = p; q; q = q->dictsuffix)
            if (q->index != -1)
                occur[q->index] = true;
    }
}

int main()
{
    //strcpy(T, "ZAABAACAAAABAAAC"); 
    strcpy(T, "abbdrqtqcde12345SAACDEAABHJ"); 

    strcpy(P[0], "AAB"); 
    strcpy(P[1], "AAC");
    strcpy(P[2], "abbd");
    strcpy(P[3], "1345");
    N = 4;

    init();     // ��l��
    for (int i=0; i<N; ++i) // �Ҧ�P�إ�trie
        add(P[i], i);
    build();    // suffix link�Bdictionary suffix link
    search(T);  // ��trie�PT�i��r��j�M
    free();     // ����O����Ŷ�
 
    for (int i=0; i<N; ++i)
        // �j�M��P�A�Ϊ̤��e�X�{�LP�C
        if (occur[i] ||
            equiv[i] != -1 && occur[equiv[i]]){
            cout << "��" << i+1 << "�Ӧr�꦳�X�{" << "\n";
        }
        else{
            cout << "��" << i+1 << "�Ӧr��S�X�{" << "\n";
        }
    system("pause"); 
}