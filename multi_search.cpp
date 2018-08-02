#include "stdafx.h"
#include "kxheap.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;


int N = 1000;   // P的個數
char T[100+1];
char P[1000][100+1];
 
bool occur[1000];   // 記錄各個P有沒有出現在T當中
int equiv[1000];    // 記錄各個P有沒有重複出現
int const ASCII_COUNT = 128;

struct TrieNode
{
    TrieNode* l[ASCII_COUNT], *suffix, *dictsuffix;
    int index;  // P的編號
 
    TrieNode()
    {
        memset(l, 0, sizeof(l));
        suffix = 0;
        dictsuffix = 0;
        index = -1;
    }
} *root;
 
// 初始化
void init()
{
    memset(occur, false, sizeof(occur));
    memset(equiv, -1, sizeof(equiv));
    root = new TrieNode();
}
 
// 砍掉整棵trie
void free(TrieNode* p = root)
{
    for (int i=0; i<ASCII_COUNT; ++i)
        if (p->l[i])
            free(p->l[i]);
    delete p;
}
 
// 把一個字串加入trie
void add(char* s, int index)
{
    TrieNode* p = root;
    for (; *s; ++s)
    {
        if (!p->l[*s])
            p->l[*s] = new TrieNode();
            
        p = p->l[*s];
    }
 
    // 如果此字串之前有出現，就特別記錄起來。    
    if (p->index == -1)
        p->index = index;
    else
        equiv[index] = p->index;
}
 
// 添上suffix link和dictionary suffix link
// 以BFS順序進行
// 時間複雜度O(?(Pi))
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
                // 添上 suffix link
                TrieNode* q = p->suffix;
                while (q && !q->l[i]) 
                    q = q->suffix;
                if (q) 
                    p->l[i]->suffix = q->l[i];
                else   
                    p->l[i]->suffix = root;
 
                // 添上 dictionary suffix link
                TrieNode* r = p->l[i]->suffix;
                if (r->index != -1) 
                    p->l[i]->dictsuffix = r;
                else 
                    p->l[i]->dictsuffix = r->dictsuffix;
 
                *qb++ = p->l[i];
            }
    }
}
 
// 拿trie與T進行字串搜尋
// 時間複雜度O(T+K)
void search(char* s)
{
    TrieNode* p = root;
    for (; *s; ++s)
    {
        // 不斷比對字元，直到比對成功。
        // 此部分總計時間複雜度為O(T)。
        while (p && !p->l[*s]) 
            p = p->suffix;

        if (p) 
            p = p->l[*s];
        else 
            p = root;
 
        // 走dictionary suffix link找到所有相符的P。
        // 此部分總計時間複雜度為O(K)。
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

    init();     // 初始化
    for (int i=0; i<N; ++i) // 所有P建立trie
        add(P[i], i);
    build();    // suffix link、dictionary suffix link
    search(T);  // 拿trie與T進行字串搜尋
    free();     // 釋放記憶體空間
 
    for (int i=0; i<N; ++i)
        // 搜尋到P，或者之前出現過P。
        if (occur[i] ||
            equiv[i] != -1 && occur[equiv[i]]){
            cout << "第" << i+1 << "個字串有出現" << "\n";
        }
        else{
            cout << "第" << i+1 << "個字串沒出現" << "\n";
        }
    system("pause"); 
}