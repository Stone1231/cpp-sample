// c161.cpp : 定義主控台應用程式的進入點。
/* 程式範例: Ch16-2-1.cpp */
#include "stdafx.h"
#include <stdlib.h>
#define MAX 6
using namespace std;
// stack類別宣告
template <class T>
class node
{
  public:
    T data;      // 成員資料
    node *next;  // 指向下一個節點
    node(T data) // 建構子
    {
        this->data = data;
        this->next = NULL;
    }
};
// list類別宣告
template <class T>
class list
{
  private:
    node<T> *first; // 成員資料
  public:
    list() { first = NULL; } // 建構子
    bool isListEmpty();      // 成員函數的宣告
    void insertNode(T d);
    T fetchNode();
};
// 成員函數: 檢查串列是否是空的
template <class T>
bool list<T>::isListEmpty()
{
    if (first == NULL)
        return true;
    else
        return false;
}
// 成員函數: 在串列開頭插入節點
template <class T>
void list<T>::insertNode(T d)
{
    // 配置節點記憶體 */
    node<T> *newnode = new node<T>(d);
    newnode->next = first; // 連結串列節點
    first = newnode;
}
// 成員函數: 在串列開頭取出節點
template <class T>
T list<T>::fetchNode()
{
    node<T> *current = first; // 目前的串列指標
    // 檢查串列是否是空的
    if (!isListEmpty())
    { // 重設串列指標
        T data = current->data;
        first = current->next;
        delete current; // 釋放節點記憶體
        return data;    // 傳回資料
    }
    else
        return -1;
}
// stack結構宣告, 繼承自樣板類別list
template <class T>
class stack : public list<T>
{
  public:
    stack() : list<T>() {} // 建構子
    ~stack() {}            // 解構子
    // 成員函數宣告
    bool isEmpty() { return isListEmpty(); }
    void push(T d) { insertNode(d); }
    T pop() { return fetchNode(); }
};
// 主程式
int main()
{
    // 宣告物件變數
    stack<double> st;
    // 宣告變數
    double data[MAX] = {2.3, 23.4, 45.6, 67.8, 78.9, 82.3};
    int i;
    cout << "存入堆疊資料的順序: ";
    // 使用迴圈將資料存入堆疊
    if (st.isEmpty())
        for (i = 0; i < MAX; i++)
        {
            st.push(data[i]);
            cout << "[" << data[i] << "]";
        }
    cout << "\n取出堆疊資料的順序: ";
    while (!st.isEmpty()) // 取出堆疊資料
    {
        cout << "[" << st.pop() << "]";
    }
    cout << "\n";
    system("PAUSE");
    return 0;
}