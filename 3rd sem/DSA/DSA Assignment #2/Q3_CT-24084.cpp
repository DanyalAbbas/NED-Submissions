#include <bits/stdc++.h>
using namespace std;

string DeciToBinary(int decimal)
{
    stack<int> st;
    string binary;
    while (decimal >= 1)
    {
        st.push(decimal%2);
        decimal /= 2;
    }

    while (!st.empty())
    {
        binary += to_string(st.top());
        st.pop();
    }

    return binary;
}


int main()
{
    int n = 20;
    string bin = DeciToBinary(n);
    cout<<bin<<endl;
}