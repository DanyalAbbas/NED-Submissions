#include <bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    if (s.size() == 0)
        return s;
    return reverse(s.substr(1)) + s[0];
}

int main()
{
    cout<<reverse("Danyal")<<endl;
}