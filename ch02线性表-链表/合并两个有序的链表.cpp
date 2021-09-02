#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

//节点类型
struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}
    int data_;
    Node *next_;
};

//单链表代码实现

class Clink
{
public:
    Clink()
    {
        //给head_初始化指向头节点
        head_ = new Node();
    }
    ~Clink()
    {
        Node *p = head_;

        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }

public:
    //链表的尾插法
    void InsertTail(int data_)
    {
        //先找到当前链表的尾节点 O(n)
        Node *p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }

        Node *node = new Node(data_);

        p->next_ = node;
        // node->next_ = nullptr;
    }

    void Inserthead(int data_) //0(1)
    {
        Node *p = head_;
        Node *node = new Node(data_);

        node->next_ = head_->next_;
        p->next_ = node;
    }
    //链表节点的删除
    void Remove(int data_)
    {
        Node *p = head_;
        Node *q = head_->next_;

        while (q != nullptr)
        {
            if (q->data_ == data_)
            {
                p->next_ = q->next_;
                delete q;
                return;
            }
            else
            {
                p = q;
                q = q->next_;
            }
        }
    }

    void RemoveAll(int data_)
    {
        Node *p = head_;
        Node *q = head_->next_;

        while (q != nullptr)
        {
            if (q->data_ == data_)
            {
                p->next_ = q->next_;
                delete q;
                //对指针p进行重置
                q = p->next_;
            }
            else
            {
                p = q;
                q = q->next_;
            }
        }
    }
    //搜索
    bool Find(int data_)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == data_)
            {
                return true;
            }
            else
            {
                p = p->next_;
            }
        }
        return false;
    }
    void show()
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }

private:
    Node *head_;

    friend void ReverseLink(Clink &link);
    friend void MergeLink(Clink &l1, Clink &l2);
};

void MergeLink(Clink &l1, Clink &l2)
{
    Node *p = l1.head_->next_;
    Node *q = l2.head_->next_;
    Node *last = l1.head_;
    l2.head_->next_ = nullptr;

    while (p != nullptr && q != nullptr)
    {
        if (p->data_ < q->data_)
        {
            last->next_ = p;
            p = p->next_;
        }
        else
        {
            last->next_ = q;
            q = q->next_;
        }
        last = last->next_;
    }
    if (p != nullptr)
    {
        last->next_ = p;
    }
    else
    {
        last->next_ = q;
    }
}

int main()
{
    int arr[] = {25, 37, 52, 78, 88, 92, 98, 108};
    int brr[] = {13, 23, 40, 56, 62, 77, 109};
    Clink l1;
    Clink l2;
    for (int v : arr)
    {
        l1.InsertTail(v);
    }
    for (int v : brr)
    {
        l2.InsertTail(v);
    }
    l1.show();
    l2.show();
    MergeLink(l1, l2);
    l1.show();
}

//leetcode实现
#if 0
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head1 = new ListNode(0,l1);
        ListNode *head2 = new ListNode(0,l2);

        ListNode *p = head1->next;
        ListNode *q = head2->next;
        ListNode *last = head1;

        while(p != nullptr && q != nullptr)
        {
            if(p->val< q->val)
            {
                last->next = p;
                p = p->next;
                last = last->next;
            }
            else
            {
                last->next = q;
                q = q->next;
                last = last->next;
            }
        }
        if(q == nullptr)
        {
            last->next = p;
        }
        else
        {
            last->next = q;
        }
        return head1->next;
    
    }
};
#endif