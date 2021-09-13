#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

// 单向循环链表
class CirCleLink
{

public:
    CirCleLink()
    {
        head_ = new Node();
        tail_ = head_;
        head_->next_ = head_;
    }
    ~CirCleLink()
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }
        delete head_;
        head_ = nullptr;
    }

public:
    //尾插法
    void InsertTail(int val)
    {
        Node *node = new Node(val);
        node->next_ = tail_->next_;
        tail_->next_ = node;
        tail_ = node; //更新tail指针
    }

    //头插法
    void InsertHead(int val)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
        if (node->next_ == head_)
        {
            tail_ = node;
        }
    }

    //删除节点
    void Remove(int val)
    {
        Node *q = head_;
        Node *p = head_->next_;

        while (p != head_)
        {
            if (p->data_ == val)
            {
                //找到删除节点
                q->next_ = p->next_;
                delete p;
                if (q->next_ == head_)
                {
                    tail_ = q;
                }
                return;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
    }

    //
    bool Find(int val)
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                return true;
            }
        }
        return false;
    }

    //打印链表
    void show() const
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
    struct Node
    {
        Node(int data = 0) : data_(data), next_(nullptr) {}
        int data_;
        Node *next_;
    };

    Node *head_;
    Node *tail_;
};

int main()
{
    CirCleLink clink;
    srand(time(0));
    clink.InsertHead(50);

    for (int i = 0; i < 10; i++)
    {
        clink.InsertTail(rand() % 100);
    }
    clink.show();

    clink.InsertTail(200);

    clink.show();

    clink.Remove(200);

    clink.show();

    clink.InsertTail(200);

    clink.show();
}
