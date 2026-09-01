#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) // 0 1 1 2 3 5 8 13 21 34 55
{
    if (n == 1 || n == 0)
        return n;
    return fibonacci(n-2) + fibonacci(n-1);
}

int main()
{
    cout<<fibonacci(5)<<endl;
}