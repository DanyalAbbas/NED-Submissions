#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int left, int right)
{
    if (left >= right) 
        return true;
    
    if (s[left] != s[right]) 
        return false;

    return isPalindrome(s, left + 1, right - 1);
}

int main()
{
    cout<<isPalindrome("racecar", 0, 6)<<endl;
    cout<<isPalindrome("danyal", 0, 5)<<endl;
}