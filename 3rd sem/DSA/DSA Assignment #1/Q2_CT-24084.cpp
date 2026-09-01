#include <bits/stdc++.h>
using namespace std;

/*Create a function that takes a list of integers and returns True if the list contains duplicate
elements, otherwise return False.*/

bool containsDuplicate(vector<int>& arr)
{
    // we will again use an hashtable for this
    unordered_map<int,bool> map;

    // loop through the array
    for (int i : arr)
    {
        // if theres a value already in array, we immediately return true
        if(map.find(i) != map.end())
            return true;
        map[i] = true;
    }
    
    // if the compiler even got here, that means there were no duplicates so return false
    return false;
}

int main()
{
    vector<int> temp = {1,2,2,4,5};
    
    if(containsDuplicate(temp))
        cout<<"Duplicate Found"<<endl;
    else
        cout<<"Nuhuh"<<endl;
    

}