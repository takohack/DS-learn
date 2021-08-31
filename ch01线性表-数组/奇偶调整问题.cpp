#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

//整形数组 把偶数调整到数组左边 奇数调整到数组右边

void AdjustArray(int arr[], int size)
{
    int *p = arr;
    int *q = arr + size - 1;
    while (p < q)
    {
        // while (*p % 2 == 0)
        // {
        //     p++;
        // }
        // while (*q % 2 == 1)
        // {
        //     q--;
        // }
        //2.老师的版本
        // p->奇数 位操作速度比较快 且优先级比较低
        // if ((*p & 0x1) == 0)
        // {
        //     p++;
        //     continue; //进入下一次循环
        // }

        // if ((*q & 0x1) == 1)
        // {
        //     q--;
        //     continue;
        // }

        //3.优化

        while (p < q)
        {
            if ((*p & 0x1) == 1)
            {
                break;
            }
            p++;
        }
        while (p < q)
        {
            if ((*q & 0x1) == 0)
            {
                break;
            }
            q--;
        }
        if (p < q)
        {
            int temp = *q;
            *q = *p;
            *p = temp;
            p++;
            q--;
        }
    }
}

int main()
{
    int arr[10] = {0};
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }

    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;

    AdjustArray(arr, 10);

    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
}