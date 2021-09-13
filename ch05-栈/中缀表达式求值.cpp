#include <iostream>
#include <string>
#include <stack>

#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<char, int> h{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
stack<char> op;

//中缀表达式转后缀表达式

bool Priority(char ch, char topch)
{
    if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
        return true;
    if (topch == '(' && ch != ')')
        return true;
    return false;
}

// 中缀表达式 => 后缀表达式
string MiddleToEndExpr(string expr)
{
    string result;
    stack<char> s;

    for (char ch : expr)
    {
        if (ch >= '0' && ch <= '9')
        {
            result.push_back(ch);
        }
        else
        {
            for (;;)
            {
                // 处理符号了
                if (s.empty() || ch == '(')
                {
                    s.push(ch);
                    break;
                }

                // 比较当前符号ch和栈顶符号top的优先级
                char topch = s.top();
                // Priority:true ch > topch   false ch <= topch
                if (Priority(ch, topch))
                {
                    s.push(ch);
                    break;
                }
                else
                {
                    s.pop();
                    if (topch == '(') // 如果遇见)，一直出栈，直到(
                        break;
                    result.push_back(topch);
                }
            }
        }
    }
    //如果符号栈还存留符号 直接输出到后缀表达式里面
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

string way2(string s)
{
    string result;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            result += to_string(x);
            i = j - 1;
        }

        else if (s[i] == '(')
        {
            op.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (op.top() != '(')
            {
                result += op.top();
                op.pop();
            }
            op.pop();
        }
        else
        {
            while (op.size() && h[op.top()] >= h[s[i]])
            {
                result += op.top();
                op.pop();
            }
            op.push(s[i]);
        }
    }
    while (op.size())
    {
        result += op.top();
        op.pop();
    }

    return result;
}

int main()
{
    cout << MiddleToEndExpr("(1+2)*(3+4)") << endl;
    cout << MiddleToEndExpr("2+6/(4-2)+(4+6)/2") << endl;

    cout << way2("(1+2)*(3+4)")<<endl;
    cout << way2("2+6/(4-2)+(4+6)/2")<<endl;
}
