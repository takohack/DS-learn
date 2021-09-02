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

    friend bool IsLinkCircle(Clink &link, int &val);
};

//判断单链表是否存在环 存在返回环的入口
bool IsLinkCircle(Node *head, int &val)
{
    Node *fast = head;
    Node *slow = head;

    //fast 跑的比slow快
    while (fast != nullptr && fast->next_ != nullptr)
    {
        slow = slow->next_;
        fast = fast->next_->next_;

        if (slow == fast)
        {
            //找入口节点
            fast = head;
            while (fast != slow)
            {
                slow = slow->next_;
                fast = fast->next_;
            }
            val = slow->data_;
            //快慢指针再次遇见
            return true;
        }
    }
    return false;
}

int main()
{

    Node head;

    Node n1(25), n2(67), n3(32), n4(48);
    head.next_ = &n1;
    n1.next_ = &n2;
    n2.next_ = &n3;
    n3.next_ = &n4;
    n4.next_ = &n4;
    int val;
    IsLinkCircle(&head, val);

    cout << val;
}

#if 0
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        //移动前先判空 且只用判断fast
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode *fast = head;
        ListNode *slow = head;
        //移动前先判空 且只用判断fast
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                //找节点
                fast = head;
                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }    


                return fast;
            }
        }
        return nullptr;
        
    }
};
#endif
//leetcode实现