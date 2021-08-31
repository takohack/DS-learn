#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
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
        for (int i = mCur - 1; i >= pos; i--) //mcur-1是第一个可以移动的位置
        {
            mpArr[i + 1] = mpArr[i];
        }
        mpArr[pos] = val;
        mCur++;
    }

    void erase(int pos) //先查询再删除
    {
        if (pos < 0 || pos >= mCur)
        {
            return;
        }

        for (int i = pos + 1; i < mCur; i++)
        {
            mpArr[i - 1] = mpArr[i];
        }

        mCur--;
    }
    int find(int val)
    {
        for (int i = 0; i < mCur; i++)
        {
            if (mpArr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    //打印数据
    void show() const
    {
        for (int i = 0; i < mCur; i++)
        {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }

private:
    void expand(int size) //指定size(倍数)扩容
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
    Array arr;
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100);
    }
    arr.show();
    arr.pop_back();
    arr.show();
    arr.insert(0, 200);
    arr.show();
    arr.insert(10, 4500);
    arr.insert(0, 30);
    arr.show();
    // arr.insert(1, 30);
    // arr.show();
    int pos = arr.find(4500);
    if(pos!=-1)
    {
        arr.erase(pos);
    }
    arr.show();
}