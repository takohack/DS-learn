#include <iostream>
#include <ctime>
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
    }

public:
    //链表的尾插法
    void InsertTail(int val)
    {
        //先找到当前链表的尾节点
        Node *p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }

        Node *node = new Node(val);

        p->next_ = node;
        // node->next_ = nullptr;
    }

private:
    Node *head_;
};

int main()
{
}