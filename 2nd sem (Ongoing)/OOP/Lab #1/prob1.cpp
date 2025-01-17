#include<iostream>
using namespace std;


int main()
{
    int RollNo, Total = 500, SummedValues = 0, ObtMarks;
    float Percentage; 
    cout<<"roll no pls :";
    cin>>RollNo;

    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter marks of subject "<<i+1<<endl;
        cin>>ObtMarks;
        SummedValues += ObtMarks;
    }
    Percentage = ((float)SummedValues/(float)Total)*100;
    cout<<"You obtained "<<SummedValues<<" marks out of "<<Total<<endl;
    cout<<"Your percentage is "<<Percentage<<"%"<<endl;

}