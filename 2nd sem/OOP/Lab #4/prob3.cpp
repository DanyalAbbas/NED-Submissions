#include <iostream>
using namespace std;

class Account
{
    private:
        int account_no;
        float account_bal;
        int security_code;
        static int count;
    
    public:
        Account(int accno=0, float accba=0, int sec=0) : account_no(accno), account_bal(accba), security_code(sec)
        {
            count++;
        }
    
        void display(void)
        {
            cout<<"Account Number : "<<account_no<<endl;
            cout<<"Account Balance : "<<account_bal<<endl;
            cout<<"Security Code : "<<security_code<<endl;
        }

        int getAccNum() {return account_no;}
        float getAccBal() {return account_bal;}
        int getSec() {return security_code;}
        static int getCount() {return count;}

        void setAccNum(int a) {account_no = a;}
        // void setAccBal(float a) {account_bal = a;} // not really needed
        void setSec(int s) {security_code = s;}

};

int Account::count = 0;

int main()
{
    Account ob1(323343,20,2222), ob2;
    ob1.display();
    cout<<Account::getCount()<<endl;
}