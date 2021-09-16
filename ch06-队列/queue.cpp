#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

class Queue
{
public:
    Queue(int size = 10) : cap_(size), front_(0), rear_(0), size_(0)
    {
        pQue_ = new int[cap_];
    }
    ~Queue()
    {
        delete[] pQue_;
        pQue_ = nullptr;
    }

public:
    //入队
    void push(int val)
    {
        if ((rear_ + 1) % cap_ == front_)
        {
            expand(2 * cap_);
        }
        pQue_[rear_] = val;
        rear_ = (rear_ + 1) % cap_;
        size_++;
    }

    void pop()
    {
        if (front_ == rear_)
            throw "queue is empty";
        front_ = (front_ + 1) % cap_;
        size_--;
    }

    int front() const
    {
        if (front_ == rear_)
            throw "queue is empty";
        return pQue_[front_];
    }

    int back() const
    {
        return pQue_[(rear_ - 1 + cap_) % cap_];
    }

    bool empty() const
    {
        return front_ == rear_;
    }

    int size() const
    {
        // return size_;
        int size = 0;
        for (int i = front_; i != rear_; i = (i + 1) % cap_)
        {
            size++;
        }
        return size;
    }

private:
    int *pQue_;
    int cap_; //空间容量

    int front_;
    int rear_;
    int size_;

private:
    void expand(int size)
    {
        int *p = new int[size];

        int i = 0;
        for (int j = front_; j != rear_; j = (j + 1) % cap_)
        {
            p[i++] = pQue_[j];
        }
        delete[] pQue_;
        pQue_ = p;
        cap_ = size;
        front_ = 0;
        rear_ = i;
    }
};

int main()
{
    int arr[] = { 12,4,56,7,89,31,53,75 };
    Queue que;

    for (int v : arr)
    {
        que.push(v);
    }
    
    cout << que.front() << endl;
    cout << que.back() << endl;

    que.push(100);
    que.push(200);
    que.push(300);
    cout << que.front() << endl;
    cout << que.back() << endl;

    while (!que.empty())
    {
        cout << que.front() << " " << que.back() << endl;
        que.pop();
    }
}