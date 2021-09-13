#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}
    int data_;
    Node *next_;
};

//不带头节点
void Joseph(Node *head, int k, int m)
{
    Node *p = head;
    Node *q = head;

    //q指向最后一个
    while(q->next_ != head)
    {
        q = q->next_;
    }


    for (int i = 1; i < k; i++)
    {
        q = p;
        p = p->next_;
    }

    //p->第k个人
    for (;;)
    {
        for (int i = 1; i < m; i++)
        {
            q = p;
            p = p->next_;
        }
        //删除p指向p指向的节点
        cout<<p->data_<<" ";
        if(p == q)
        {
            delete p;
            break;
        }
        q->next_ = p->next_;
        delete p;
        p = q->next_;
    }
}

int main()
{
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    head->next_ = n2;
    n2->next_ = n3;
    n3->next_ = n4;
    n4->next_ = n5;
    n5->next_ = n6;
    n6->next_ = n7;
    n7->next_ = n8;
    n8->next_ = head;

    Joseph(head, 1, 5);
}