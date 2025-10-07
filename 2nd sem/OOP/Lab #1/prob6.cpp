#include<iostream>
#include<string>
using namespace std;

void SavingsProcedure(float &balance);
void CurrentProcedure(float &balance);

int main()
{
    float balance = 200000;
    string type;
    cout<<"Which account type do you have : ";
    cin>>type;
    
    if (type == "S")
        {SavingsProcedure(balance);}
    else if (type == "C")
        {CurrentProcedure(balance);}
    else
        {cout<<"INVALID INPUT"<<endl;}
    
    cout<<"Your balance is : "<<balance<<endl;
}

void SavingsProcedure(float &balance)
{
    int withdraw;
    int AccNum;
    cout<<"Enter your account number: ";
    cin>>AccNum;
    cout<<"How much do you want to withdraw? : ";
    cin>>withdraw;
    if (withdraw > 50000 && withdraw <= 100000)
        {balance -= withdraw*0.05;}
    else if (withdraw > 100000 )
        {cout<<"nuh uh, cant withdraw more than 100k at a time ji"<<endl;
            return;}
    
    balance -= withdraw*0.02;
    balance -= withdraw;

}

void CurrentProcedure(float &balance)
{
    int withdraw;
    int AccNum;
    cout<<"Enter your account number: ";
    cin>>AccNum;
    cout<<"How much do you want to withdraw? : ";
    cin>>withdraw;
    if (withdraw > 50000 && withdraw <= 100000)
        {balance -= withdraw*0.05;}
    else if (withdraw > 100000)
        {cout<<"nuh uh, cant withdraw more than 100k at a time ji"<<endl;
            return;}
    
    balance -= 100;
    balance -= withdraw;

}