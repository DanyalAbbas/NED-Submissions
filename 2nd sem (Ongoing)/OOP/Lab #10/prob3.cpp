#include<iostream>
#include<cctype> //FOR toupper
using namespace std;

template<typename T>
class MyContainer{
	private:
		T element;
	public:
		MyContainer(char val) : element(val) {}

        void increasevalue(){element++;}

		T getelement(){return element;}

};

template<>
class MyContainer<char>{
	private:
		char element;
	public:
		MyContainer(char val) : element(val) {}

		void uppercase(){
			element=toupper(element);
		}

		char getelement(){return element;}

};

int main(void){
	MyContainer<int>intobj(99);
	intobj.increasevalue();
	cout<<"AFTER INCREASING(int): "<<intobj.getelement()<<endl;
	
	MyContainer<char>charobj('m');
	charobj.uppercase();
	cout<<"AFTER UPPERCASE(char): "<<charobj.getelement()<<endl;
	return 0;
}