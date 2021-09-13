#include <iostream>
#include <cstring>
using namespace std;

//顺序栈 C++容器适配器 stack

class SeqStack
{

public:
    SeqStack(int size = 10)
        : mtop(0), mcap(size)
    {
        mStack = new int[mcap];
    }
    ~SeqStack()
    {
        delete[] mStack;
        mStack = nullptr;
    }

public:
    //入栈
    void push(int val)
    {
        if (mtop == mcap)
        {
            //栈扩容
            expand(2 * mcap);
        }
        mStack[mtop++] = val;
    }
    //
    void pop()
    {
        if (mtop == 0)
            return;
        mtop--;
    }

    int top() const
    {
        if (mtop == 0)
            throw "stack is empty!";
        return mStack[mtop - 1];
    }

    bool empty() const
    {
        return mtop == 0;
    }

    int size() const
    {
        return mtop;
    }

private:
    int *mStack;
    int mtop;
    int mcap;
    void expand(int size)
    {
        int *p = new int[size];
        memcpy(p, mStack, mtop * sizeof(int));
        delete[] mStack;
        mStack = p;
        mcap = size;
    }
};
int main()
{
    int arr[] = {12, 4, 56, 7, 89, 31, 53, 75};
    SeqStack s;

    for (int v : arr)
    {
        s.push(v);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}