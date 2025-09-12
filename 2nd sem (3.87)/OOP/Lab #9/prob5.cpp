#include <iostream>
#include <string>
using namespace std;
class DecryptionTechnique {
public:
    virtual string decrypt(string msg) = 0;
};
class DecryptionTechnique1 : public DecryptionTechnique {
public:
    string decrypt(string msg) {
        string decrypted = "";
        for (int i = 0; i < msg.length(); i += 2) {
            string temp = msg.substr(i, 2);
            int ascii = stoi(temp);
            decrypted += (char)ascii;
        }
        return decrypted;
    }
};
class DecryptionTechnique2 : public DecryptionTechnique {
public:
    string decrypt(string msg) {
        string decrypted = "";
        for (int i = 0; i < msg.length(); i += 2) {
            string temp = msg.substr(i, 2);
            int ascii = stoi(temp) - 2;
            decrypted += (char)ascii;
        }
        return decrypted;
    }
};
int main() {
    string encrypted1, encrypted2;
    cout << "Enter encrypted message (Technique 1): ";
    cin >> encrypted1;
    cout << "Enter encrypted message (Technique 2): ";
    cin >> encrypted2;
    DecryptionTechnique1 dec1;
    DecryptionTechnique2 dec2;
    string d1 = dec1.decrypt(encrypted1);
    string d2 = dec2.decrypt(encrypted2);
    cout << "Decrypted Technique 1: " << d1 << endl;
    cout << "Decrypted Technique 2: " << d2 << endl;
    return 0;
}