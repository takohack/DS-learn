#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void reverse_char(char arr[], int size)
{
    char *p = arr;
    char *q = arr + size - 1;
    while (p < q)
    {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
}

void reverse_string(string &arr, int size)
{
    int p = 0, q = size - 1;
    while (p < q)
    {
        char ch = arr[p];
        arr[p] = arr[q];
        arr[q] = ch;
        p++, q--;
    }
}

int main()
{
    char a[] = "hello world";
    string arr("hello world");
    reverse_char(a, strlen(a));
    cout << a<<endl;
    reverse_string(arr, arr.size());
    cout << arr;
}