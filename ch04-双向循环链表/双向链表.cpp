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

//双向链表
class DoubleLink
{
public:
    DoubleLink()
    {
        head_ = new Node();
    }
    ~DoubleLink()
    {
        Node *p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
    }

public:
    void InsertHead(int val)
    {
        //head的后向指针与不能先改
        //先改自己的
        Node *node = new Node(val);

        node->next_ = head_->next_;
        node->pre_ = head_;
        if (head_->next_ != nullptr)
            head_->next_->pre_ = node;
        head_->next_ = node;
    }

    void InsertTail(int val)
    {
        Node *p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }
        Node *node = new Node(val);

        node->pre_ = p;
        p->next_ = node;
    }
    void Remove(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                p->pre_->next_ = p->next_;

                if (p->next_ != nullptr)
                {
                    p->next_->pre_ = p->pre_;
                }
                Node *next = p->next_;
                delete p;
                p = next;
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
        while(p!=nullptr)
        {
            if(p->data_ == val)
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

int main()
{
    DoubleLink dlink;
    dlink.InsertTail(10);
    dlink.InsertTail(12);
    dlink.InsertTail(13);
    dlink.InsertHead(100);
    dlink.InsertTail(100);
    dlink.Show();
    dlink.Remove(100);
    dlink.Show();
}