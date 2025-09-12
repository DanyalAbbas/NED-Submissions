#include<iostream>
using namespace std;

template<typename T1,typename T2>
void swapdata(T1 &num1,T2 &num2){
	T1 temp=num1;
	num1=num2;
	num2=temp;
}

int main(void){
	int a=10;
	int b=20;
	cout<<"BEFORE SWAPPING int a= "<<a<<",int b= "<<b<<endl;
	swap(a,b);
	cout<<"AFTER SWAPPING int a= "<<a<<",int b= "<<b<<endl;
	
	
	float x=5.5;
	float y=8.9;
	cout<<"BEFORE SWAPPING float x= "<<x<<",float y= "<<y<<endl;
	swap(x,y);
	cout<<"AFTER SWAPPING float x= "<<x<<",float y= "<<y<<endl;
}