#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class Game{
	private:
		int noofplayers;
		int publicnumber;
		int secretnumber;
	public:
	Game(int n,int p,int s){
		noofplayers=n;
	    publicnumber=p;
		secretnumber=s;
	}
	int getplayers(){
		return noofplayers;
	}
	int getpnumber(){
		return publicnumber;
	}
	int getsnumber(){
		return secretnumber;
	}
	
};

int main(void){
	srand(time(0));
	
	int noofplayers=rand();
	cout<<"Number Of Players:"<<noofplayers<<endl;
	
	int publicnumber;
	int secretnumber;
	cout<<"Enter public number"<<endl;
	cin>>publicnumber;
	cout<<"Enter secret number"<<endl;
	cin>>secretnumber;
	if(publicnumber==secretnumber){
		cout<<"Enemy got hit by your team!"<<endl;
	}
	else{
		cout<<"You got hit by the enemy team!"<<endl;
	}
	return 0;
}