#include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, char src, char dest, char auxi)
{
    if (n == 1)
    {
        cout<<"Transfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    TowerOfHanoi(n-1, src, auxi, dest);
    cout<<"Transfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    TowerOfHanoi(n-1, auxi, dest , src);

}   


int main()
{
    TowerOfHanoi(3, 'A', 'C', 'B');
}