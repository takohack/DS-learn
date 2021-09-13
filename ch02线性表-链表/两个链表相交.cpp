//哈希表  2.双指针应用->快慢指针

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
};

bool IsLinkHasMerge(Node *head1, Node *head2, int &val)
{
    int len1 = 0, len2 = 0;
    Node *p = head1->next_, *q = head2->next_;
    while (p != nullptr)
    {
        p = p->next_;
        len1++;
    }
    while (q != nullptr)
    {
        q = q->next_;
        len2++;
    }

    p = head1;
    q = head2;
    if (len1 > len2)
    {
        int offset = len1 - len2;
        while (offset--)
        {
            p = p->next_;
        }
    }
    else
    {
        int offset = len2 - len1;
        while (offset--)
        {
            q = q->next_;
        }
    }
    while (p != nullptr)
    {
        if (p == q)
        {
            val = p->data_;
            return true;
        }
        p = p->next_;
        q = q->next_;
    }
    return false;
}

int main()
{
    Node head1;
    Node n1(25), n2(67), n3(32), n4(18);
    head1.next_ = &n1;
    n1.next_ = &n2;
    n2.next_ = &n3;
    n3.next_ = &n4;

    Node head2;
    Node n5(31);
    head2.next_ = &n5;
    n5.next_ = &n3;

    int val;
    if (IsLinkHasMerge(&head1, &head2, val))
    {
        cout << "链表相交，相交节点是：" << val << endl;
    }
}