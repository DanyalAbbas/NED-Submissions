#include <bits/stdc++.h>
using namespace std;


bool isValidParenthesis(string str)
{
    unordered_map<char, char> map;
    map[')'] = '(';
    map[']'] = '[';
    map['}'] = '{';


    stack<char> st;
    for (char i : str)
    {
        if (i == '[' || i == '(' || i == '{' )
            st.push(i);
        else if (!st.empty() && map[i] == st.top())
            st.pop();
        else
            return false;
    }

    return true;

}


int main()
{
    string param = "()()()";
    if(isValidParenthesis(param))
        cout<<"Valid Parenthesis"<<endl;
    else
        cout<<"Not Valid Parenthesis"<<endl;
}






