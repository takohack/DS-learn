//括号匹配

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> cs;

        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                cs.push(ch);
            }
            else
            {
                if(cs.empty())
                    return false;

                char cmp = cs.top();
                cs.pop();

                if (ch == ')' && cmp != '(' ||
                    ch == ']' && cmp != '[' ||
                    ch == '}' && cmp != '{')
                {
                    return false;
                }
            }
        }
        //
        // if(!cs.empty())
        //     return false;
        // return true;
        return cs.empty();
    }
};


//逆波兰式

class Solution
{
public:
    int calc(int left, int right, char sign)
    {
        switch (sign)
        {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        }
        throw "";
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> intStack;

        for (string &str : tokens)
        {
            if (str.size() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*'))
            {
                //遇到运算符了 开始运算
                int right = intStack.top();
                intStack.pop();

                int left = intStack.top();
                intStack.pop();

                intStack.push(calc(left, right, str[0]));
            }
            else
            {
                //遇到数字
                //string => int stoi
                //int => string to_string()
                intStack.push(stoi(str));
            }
        }
        return intStack.top();
    }
    
};

//中缀转后缀