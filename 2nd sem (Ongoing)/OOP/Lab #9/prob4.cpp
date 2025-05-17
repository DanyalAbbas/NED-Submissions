#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class EncryptionTecnique {
public:
    virtual string encrypt(string msg) = 0;
};
class EncryptionTecnique1 : public EncryptionTecnique {
public:
    string encrypt(string msg) {
        string encrypted = "";
        for (int i = 0; i < msg.length(); i++) {
            msg[i] = toupper(msg[i]);
            encrypted += to_string((int)msg[i]);
        }
        return encrypted;
    }
};
class EncryptionTecnique2 : public EncryptionTecnique {
public:
    string encrypt(string msg) {
        string encrypted = "";
        for (int i = 0; i < msg.length(); i++) {
            msg[i] = toupper(msg[i]);
            encrypted += to_string((int)msg[i] + 2);
        }
        return encrypted;
    }
};
int main() {
    string input;
    cout << "Enter message to encrypt: ";
    cin >> input;
    EncryptionTecnique1 enc1;
    EncryptionTecnique2 enc2;
    string e1 = enc1.encrypt(input);
    string e2 = enc2.encrypt(input);
    cout << "Encrypted Technique 1: " << e1 << endl;
    cout << "Encrypted Technique 2: " << e2 << endl;
    return 0;
}

