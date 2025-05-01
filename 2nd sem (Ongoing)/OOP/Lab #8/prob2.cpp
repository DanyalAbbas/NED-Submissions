#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int level;
    int health;

public:
    Character(string n, int l, int h) : name(n), level(l), health(h) {}

    virtual void ShowAbilities() {
        cout << name << " has basic character traits." << endl;
    }

    virtual ~Character() {}
};

class Warrior : virtual public Character {
protected:
    int strength;
public:
    Warrior(string n, int l, int h, int str)
        : Character(n, l, h), strength(str) {}

    void Slash() {
        cout << name << " performs a powerful slash!" << endl;
    }

    void ShowAbilities() override {
        cout << name << " has warrior abilities: Strength = " << strength << ", Slash ability." << endl;
    }
};

class Mage : virtual public Character {
protected:
    int intelligence;
public:
    Mage(string n, int l, int h, int intel)
        : Character(n, l, h), intelligence(intel) {}

    void Fireball() {
        cout << name << " casts a fireball!" << endl;
    }

    void ShowAbilities() override {
        cout << name << " has mage abilities: Intelligence = " << intelligence << ", Fireball spell." << endl;
    }
};

class Archer : public Character {
protected:
    int dexterity;
public:
    Archer(string n, int l, int h, int dex)
        : Character(n, l, h), dexterity(dex) {}

    void RapidShot() {
        cout << name << " shoots arrows rapidly!" << endl;
    }

    void ShowAbilities() override {
        cout << name << " has archer abilities: Dexterity = " << dexterity << ", Rapid shot." << endl;
    }
};

class NPC : public Character {
public:
    NPC(string n, int l, int h)
        : Character(n, l, h) {}

    void ShowAbilities() override {
        cout << name << " follows a scripted dialogue and movement path." << endl;
    }
};

class Mighty : public Warrior, public Mage {
public:
    Mighty(string n, int l, int h, int str, int intel)
        : Character(n, l, h), Warrior(n, l, h, str), Mage(n, l, h, intel) {}

    void ShowAbilities() override {
        cout << name << " is a Mighty character with combined abilities:" << endl;
        Warrior::ShowAbilities();
        Mage::ShowAbilities();
    }
};

int main() {
    Character* characters[5];

    characters[0] = new Warrior("Thor", 10, 100, 80);
    characters[1] = new Mage("Merlin", 12, 70, 95);
    characters[2] = new Archer("Legolas", 9, 85, 90);
    characters[3] = new NPC("Villager", 1, 30);
    characters[4] = new Mighty("Gandor", 20, 150, 90, 100);

    for (int i = 0; i < 5; i++) {
        characters[i]->ShowAbilities();
        cout << endl;
    }
}
