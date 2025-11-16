#include<bits/stdc++.h>
using namespace std;


bool BubbleSort(vector<int> &test)
{
    bool swapped = false;
    for( int i = 0; i < test.size() ; i++ ){
        for( int j = i; j < test.size(); j++){
            if(test[i] > test[j]){
                swap(test[i],test[j]);
                swapped = true;
            }
        }
    }
        return swapped;
}


int main(){
    vector<int> testing = {4,3,16,5};
    cout<<BubbleSort(testing)<<endl;
    for(int k = 0; k < testing.size(); k++){
        cout<< testing[k];
    }
}