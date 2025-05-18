#include<iostream>
using namespace std;
template<typename T1,typename T2>

class Calculator{
	private:
		T1 num1;
		T2 num2;
	public:
		Calculator(T1 a,T2 b){
			num1=a;
			num2=b;
		}
		auto add(){
			return num1+num2;
		}
		auto subtract(){
			return num1-num2;
		}
		auto multiply(){
			return num1*num2;
		}
		auto divide(){
			return num1/num2;
		}
};

int main(void){
	Calculator<int,int> obj1(10,2);
	cout<<obj1.add()<<endl;
	cout<<obj1.subtract()<<endl;
	cout<<obj1.multiply()<<endl;
	cout<<obj1.divide()<<endl;
	
	Calculator<int,float> obj2(3,6.6);
	cout<<obj2.add()<<endl;
	cout<<obj2.subtract()<<endl;
	cout<<obj2.multiply()<<endl;
	cout<<obj2.divide()<<endl;
	
}

