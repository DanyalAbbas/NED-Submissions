#include <bits/stdc++.h>
using namespace std;

string reverseString(string str)
{
    stack<char> st;
    string reversed;

    for(char i : str)
        st.push(i);

    while(!st.empty())
    {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}

int main()
{
    string str = "Danyal";
    string reversed = reverseString(str);
    cout<<reversed<<endl;
}