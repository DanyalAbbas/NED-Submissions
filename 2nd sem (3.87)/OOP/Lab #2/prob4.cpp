#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class Game{
	private:
		int NoOfPlayers;
		int SecretNumber1;
		int SecretNumber2;
        int Hits;

	public:
        void setAll()
        {
            srand(time(0));
            NoOfPlayers = (rand() % 5)+1;
            Hits = NoOfPlayers;
        }
        int getPlayers() {return NoOfPlayers;}
        int getSecret1() {return SecretNumber1;}
        int getSecret2() {return SecretNumber2;}

        void Play()
        {
            int EnemyScore = 0, YourScore = 0;
            cout<<"Total Number of Players in your team: "<<NoOfPlayers<<endl<<endl;

            for (int i = 0; i < Hits; i++)  
            {
                cout<<"Pair of numbers:"<<endl;
                SecretNumber1 = (rand() % 10)+1;
                cout<<"Number 1 : "<<SecretNumber1<<endl;
                SecretNumber2 = (rand() % 10)+1;
                cout<<"Number 2 : "<<SecretNumber2<<endl;
                if (SecretNumber1 == SecretNumber2)
                {
                    YourScore++;
                    cout<<"Enemy got hit by your team!"<<endl<<endl;
                } 
                else
                {
                    EnemyScore++;
                    cout<<"You got hit by the enemy team!"<<endl<<endl;
                }
            }

            if (YourScore > EnemyScore) {cout<<"Game Over! You Won"<<endl;}
            else if (EnemyScore > YourScore) {cout<<"Game Over! Enemy Won"<<endl;}
            else {cout<<"Game Over! It was a Draw"<<endl;}


        }
	
};


int main()
{
    Game g1;
    g1.setAll();
    g1.Play();
}