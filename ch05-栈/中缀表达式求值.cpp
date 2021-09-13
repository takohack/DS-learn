#include <iostream>
#include <string>
#include <stack>

using namespace std;

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

int main()
{
    cout << MiddleToEndExpr("(1+2)*(3+4)") << endl;
}
