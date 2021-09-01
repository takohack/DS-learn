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
    void InsertTail(int val)
    {
        //先找到当前链表的尾节点 O(n)
        Node *p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }

        Node *node = new Node(val);

        p->next_ = node;
        // node->next_ = nullptr;
    }

    void Inserthead(int val) //0(1)
    {
        Node *p = head_;
        Node *node = new Node(val);

        node->next_ = head_->next_;
        p->next_ = node;
    }
    //链表节点的删除
    void Remove(int val)
    {
        Node *p = head_;
        Node *q = head_->next_;

        while (q != nullptr)
        {
            if (q->data_ == val)
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

    void RemoveAll(int val)
    {
        Node *p = head_;
        Node *q = head_->next_;

        while (q != nullptr)
        {
            if (q->data_ == val)
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
    bool Find(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
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
};

int main()
{
    Clink link;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100;
        //link.InsertTail(val);
        link.Inserthead(val);
        cout << val << " ";
    }
    cout << endl;
    link.InsertTail(500);
    link.Inserthead(23);
    link.Inserthead(23);
    link.show();
    link.RemoveAll(23);

    link.show();
}