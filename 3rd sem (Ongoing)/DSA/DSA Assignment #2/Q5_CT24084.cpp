#include <bits/stdc++.h>
using namespace std;



int evaluatePostfix(string postfix) {
    vector<int> stack;
    for (char token : postfix)
    {
        if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            int b = stack.back(); stack.pop_back();
            int a = stack.back(); stack.pop_back();
            if (token == '+') stack.push_back(a + b);
            else if (token == '-') stack.push_back(a - b);
            else if (token == '*') stack.push_back(a * b);
            else if (token == '/') stack.push_back(a / b);
        }
        else if (token == ' ') continue;
        else
        {
            stack.push_back(token - '0');
        }
    }
    return stack[0];
}


int main()
{
    string p = "5 6 2 + * 1 2 4";
    int i = evaluatePostfix(p);
    cout<<i<<endl;

}