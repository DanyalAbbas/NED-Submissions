#include <bits/stdc++.h>
using namespace std;

string InfixToPostfix(string infix)
{
    unordered_map<char, int> precedence;
    precedence['^'] = 3;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['+'] = 1;
    precedence['-'] = 1;
    

    stack<char> st;
    string postfix;

    for(char i : infix)
    {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
            postfix += i;

        else if (i == '(')
            st.push(i);
        
        else if (i == ')')
        {
            while (!st.empty() && st.top() != '(' )
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && st.top() != '(' && (precedence[st.top()] >= precedence[i] && i != '^'))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(i);
        }

    }
    
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }


    
    return postfix;
}


int main()
{
    string s = "(A+B)*C";
    string j = InfixToPostfix(s);
    cout<<j<<endl;
}