#include <iostream>
using namespace std;

class Weapons
{
    public:
        void WeaponsDescription(void)
        {
            cout<<"Weapons are used to kill people."<<endl;
        }
};
class HotWeapons: public Weapons
{
    public:
        void HotWeaponsDescription(void)
        {
            cout<<"Hot Weapons use gunpowder."<<endl;
        }
};
class Bombs: public HotWeapons
{
    public:
        void BombsDescription(void)
        {
            cout<<"Bombs blow up."<<endl;
        }
};
class NuclearBombs: public Bombs
{
    public:
        void NuclearBombsDescription(void)
        {
            cout<<"Nuclear bombs blow up, and use nuclear fission and fusion."<<endl;
        }
};

int main()
{
    NuclearBombs ob1;
    ob1.WeaponsDescription();
    ob1.HotWeaponsDescription();
    ob1.BombsDescription();
    ob1.NuclearBombsDescription();
}