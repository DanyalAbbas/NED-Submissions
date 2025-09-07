#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int rmin = 0, rmax = m-1;
        while(rmin <= rmax){
            int rmid = rmin + ((rmax-rmin)/2);
            if(target < matrix[rmid][0]) rmax = rmid - 1;
            else if (target > matrix[rmid][n-1]) rmin = rmid + 1;
            else {
                int xmin = 0, xmax = n-1;
                while(xmin <= xmax) {
                    int xmid = xmin + ((xmax-xmin)/2);
                    if(matrix[rmid][xmid] == target) return true;
                    if(matrix[rmid][xmid] < target) xmin = xmid + 1;
                    else xmax = xmid - 1;
                }
                return false;
            }
        }

        return false;
    }


int main(void){
    int m,n;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n));
    cout<<"Enter elements of matrix: "<<endl;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];

    int target;
    cout<<"Enter target element: ";
    cin>>target;

    if(searchMatrix(matrix,target)) 
        cout<<"Element found!"<<endl;
    else cout<<"Element not found!"<<endl;

}