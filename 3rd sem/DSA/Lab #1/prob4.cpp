#include <iostream>
using namespace std;


int search(int* nums, int numsSize, int target) {
    int low;
    int high;
    int res=-1;
    low=0;
    high=numsSize-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            res=mid;
            break;
        }
    }
    return res;
}

int main(void){
    int arr[10] = {1,3,5,7,9,11,13,15,17,19};
    int n=10;
    
    int target;
    cout<<"Enter target element: ";
    cin>>target;

    int result=search(arr,n,target);
    if(result==-1)
        cout<<"Element not found!"<<endl;
    else
        cout<<"Element found at index "<<result<<endl;
}

