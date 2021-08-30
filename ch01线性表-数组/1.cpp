#include <iostream>
#include <cstring>
using namespace std;

class Array
{
public:
    Array(int size = 10) : mCur(0), mCap(size)
    {
        mpArr = new int[mCap](); //小括号初始为int 0值
    }
    ~Array()
    {
        delete[] mpArr;
        mpArr = nullptr;
    }

public:
    void push_back(int val)
    {
        if (mCur == mCap)
            expand(2 * mCap);
        mpArr[mCur++] = val;
    }

    void pop_back()
    {
        if (mCur == 0)
        {
            return;
        }
        mCur--;
    }

    void insert(int pos, int val)
    {
        if (pos < 0 || pos > mCur)
        {
            return; //throw "pos invalid"
        }
        if (mCur == mCap)
            expand(2 * mCap);
        for(int i=mCur-1;i>=pos;i--)
        {
            mpArr[i+1] = mpArr[i];
        }
        mpArr[pos] == val;
        mCur++;
    }

    void erase(int val);

    int find(int val);

private:
    void expand(int size)
    {
        int *p = new int[size];
        memcpy(p, mpArr, sizeof(int) * mCap);
        delete[] mpArr;
        mpArr = p;
        mCap = size;
    }

private:
    int *mpArr; //指向可扩容数组的内存
    int mCap;   //数组容量
    int mCur;   //数组有效元素个数
};

int main()
{
    Array arr(10);
    for(int i=3;i>=3;i--)
    {
        cout<<"test"<<endl;
    }

}