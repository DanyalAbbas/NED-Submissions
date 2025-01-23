#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    private:
        const float InterestRate = 0.05;
        float Balance;
        int NumOfTransactions;
        float InterestEarned;
    public:
        BankAccount(float b)
        {
            Balance = b;
            NumOfTransactions = 0;
            InterestEarned = 0;
        }
        void deposit(float amount)
        {
            if (amount > Balance)
                {cout<<"Invalid Input"<<endl;}
            else
                {Balance += amount;}
            NumOfTransactions++;

        }
        void withdraw(float amount)
        {
            if (amount > Balance)
                {cout<<"Invalid Input"<<endl;}
            else
                {Balance -= amount;}
            NumOfTransactions++;
        }
        int GetNT(void)
        {
            return NumOfTransactions;
        }
        float CurrentBalance(void)
        {
            return Balance;
        }

        float CalculateInterest(float TimePeriod)
        {
            InterestEarned += InterestRate*TimePeriod*Balance;
            Balance += InterestEarned;
            return InterestEarned;
        }

};


int main()
{
    BankAccount acc1(50000);
    cout<<"THE ABC BANK SYSTEM"<<endl;
    cout<<"==================================="<<endl;
    cout<<"Choose any of the following options"<<endl;
    cout<<"1. Account Balance\n2. Number of Transactions\n3. Interest Earned\n4. Deposit\n5. Withdrawal\n6. Exit"<<endl;

    int choice = 0;
    while (choice != 6)
    {
        cout<<"What operation do you want to perform? : ";
        cin>>choice;
        if (choice < 1 && choice > 6)
        {
            cout<<"Invalid Choice"<<endl;
            break;
        }

        if (choice == 1)
        {
            cout<<"Your Account Balance is : "<<acc1.CurrentBalance()<<endl;
        }
        if (choice == 2)
        {
            cout<<"Your Number of Transactions are : "<<acc1.GetNT()<<endl;
        }
        if (choice == 3)
        {
            float tp;
            cout<<"Please Enter Time Period : ";
            cin>>tp;
            cout<<"Your Interest Earned is : "<<acc1.CalculateInterest(tp)<<endl;
        }
        if (choice == 4)
        {
            float d;
            cout<<"Please Enter the deposit amount : ";
            cin>>d;
            acc1.deposit(d);
            cout<<"Your Current Balance after deposit of "<<d<<" Rs is : "<<acc1.CurrentBalance()<<endl;
        }
        if (choice == 5)
        {
            float w;
            cout<<"Please Enter the deposit amount : ";
            cin>>w;
            acc1.withdraw(w);
            cout<<"Your Current Balance after withdrawal of "<<w<<" Rs is : "<<acc1.CurrentBalance()<<endl;
        }

        char select;
        cout<<"Do you want to perform more operations? (y/n) : ";
        cin>>select;
        if (select != 'y' || select != 'Y')
            {break;}


    }

}