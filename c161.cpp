// c161.cpp : �w�q�D���x���ε{�����i�J�I�C
/* �{���d��: Ch16-2-1.cpp */
#include "stdafx.h"
#include <stdlib.h>
#define MAX 6
using namespace std;
// stack���O�ŧi
template <class T>
class node
{
  public:
    T data;      // �������
    node *next;  // ���V�U�@�Ӹ`�I
    node(T data) // �غc�l
    {
        this->data = data;
        this->next = NULL;
    }
};
// list���O�ŧi
template <class T>
class list
{
  private:
    node<T> *first; // �������
  public:
    list() { first = NULL; } // �غc�l
    bool isListEmpty();      // ������ƪ��ŧi
    void insertNode(T d);
    T fetchNode();
};
// �������: �ˬd��C�O�_�O�Ū�
template <class T>
bool list<T>::isListEmpty()
{
    if (first == NULL)
        return true;
    else
        return false;
}
// �������: �b��C�}�Y���J�`�I
template <class T>
void list<T>::insertNode(T d)
{
    // �t�m�`�I�O���� */
    node<T> *newnode = new node<T>(d);
    newnode->next = first; // �s����C�`�I
    first = newnode;
}
// �������: �b��C�}�Y���X�`�I
template <class T>
T list<T>::fetchNode()
{
    node<T> *current = first; // �ثe����C����
    // �ˬd��C�O�_�O�Ū�
    if (!isListEmpty())
    { // ���]��C����
        T data = current->data;
        first = current->next;
        delete current; // ����`�I�O����
        return data;    // �Ǧ^���
    }
    else
        return -1;
}
// stack���c�ŧi, �~�Ӧۼ˪O���Olist
template <class T>
class stack : public list<T>
{
  public:
    stack() : list<T>() {} // �غc�l
    ~stack() {}            // �Ѻc�l
    // ������ƫŧi
    bool isEmpty() { return isListEmpty(); }
    void push(T d) { insertNode(d); }
    T pop() { return fetchNode(); }
};
// �D�{��
int main()
{
    // �ŧi�����ܼ�
    stack<double> st;
    // �ŧi�ܼ�
    double data[MAX] = {2.3, 23.4, 45.6, 67.8, 78.9, 82.3};
    int i;
    cout << "�s�J���|��ƪ�����: ";
    // �ϥΰj��N��Ʀs�J���|
    if (st.isEmpty())
        for (i = 0; i < MAX; i++)
        {
            st.push(data[i]);
            cout << "[" << data[i] << "]";
        }
    cout << "\n���X���|��ƪ�����: ";
    while (!st.isEmpty()) // ���X���|���
    {
        cout << "[" << st.pop() << "]";
    }
    cout << "\n";
    system("PAUSE");
    return 0;
}