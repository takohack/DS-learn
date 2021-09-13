#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

//定义双向链表的节点类型
struct Node
{
    Node(int data = 0)
        : data_(data), next_(nullptr), pre_(nullptr)
    {
    }
    int data_;
    Node *next_;
    Node *pre_;
};

//双向循环链表
class DoubleCricleLink
{
public:
    DoubleCricleLink()
    {
        head_ = new Node();
        head_->next_ = head_;
        head_->pre_ = head_;
    }
    ~DoubleCricleLink()
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            head_->next_ = p->next_;
            p->next_->pre_ = p->pre_;
            delete p;
            p = head_->next_;
        }
        delete head_;
        head_ = nullptr;
    }

public:
    void InsertHead(int val)
    {
        //head的后向指针与不能先改
        //先改自己的
        Node *node = new Node(val);

        node->next_ = head_->next_;
        node->pre_ = head_;
        head_->next_->pre_ = node;
        head_->next_ = node;
    }

    void InsertTail(int val)
    {
        Node *p = head_->pre_;

        Node *node = new Node(val);
        node->pre_ = p;
        p->next_ = node;
        node->next_ = head_;
        head_->pre_ = node;
    }
    void Remove(int val)
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                p->pre_->next_ = p->next_;
                p->next_->pre_ = p->pre_;
                delete p;
                return;
            }
            else
            {
                p = p->next_;
            }
        }
    }

    bool Find(int val)
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                return true;
            }
            else
            {
                p = p->next_;
            }
        }
    }

    void Show()
    {
        Node *p = head_->next_;

        while (p != head_)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }

private:
    Node *head_;
};

int main()
{
    DoubleCricleLink dlink;

    dlink.InsertHead(100);

    dlink.InsertTail(20);
    dlink.InsertTail(12);
    dlink.InsertTail(78);
    dlink.InsertTail(32);
    dlink.InsertTail(7);
    dlink.InsertTail(90);
    dlink.Show();

    dlink.InsertHead(200);
    dlink.Show();

    dlink.Remove(200);
    dlink.Show();

    dlink.Remove(90);
    dlink.Show();

    dlink.Remove(78);
    dlink.Show();
}