// #include<vector>
// #include<iostream>
// using namespace std;


// // int main()
// // {
// //     vector<int> v; vector<int> w(11);
// //     v.push_back(1); v.push_back(2);
// //     v.push_back(3);
// //     w.push_back(1); w.push_back(2);
// //     w.push_back(3);
// //     cout << "Size of v: " << v.size() << endl;
// //     cout << "Size of w: " << w.size() << endl;
// // }



// // string processString(string msg) {
// //     cout << "Original Message: " << msg << endl;
// //     int index = 0;
// //     while (msg[index] != '\0') {
// //         msg[index]+= 2;
// //         index++;
// //     }
// //     return msg;
// // }
// // int main() {
// //     string line = processString("OOPEXAM");
// //     cout << "Encrypted Message: " << line << endl;
// // }







// class SquareArea {
//     float sideLength;
// public:
//     SquareArea(float sideLength = 0) :
//         sideLength(sideLength) {}
//     SquareArea() : sideLength(0) {}
//     void setLength(float f) {
//         sideLength = f;
//     }
//     float calculateArea() {
//         return sideLength * sideLength;
//     }
// };
// int main() {
//     SquareArea ob;
//     ob.setLength(12);
//     cout << "Area is " << ob.calculateArea() << endl;
// }



#include <fstream>   // Required for fstream
#include <iostream>  // Required for console I/O
#include <cstring>   // Required for strcpy, strlen
using namespace std;

// class MyData {
// public:
//     int id;
//     char name[20]; // Fixed-size character array for simplicity

//     // Default constructor to ensure name is null-terminated when an object is created without args
//     MyData() : id(0) { name[0] = '\0'; }

//     MyData(int i, const char* n) : id(i) {
//         strcpy(name, n);
//         name[sizeof(name) - 1] = '\0'; // Ensure null-termination
//     }

//     void display() const {
//         cout << "ID: " << id << ", Name: " << name << endl;
//     }
// };

// int main() {
//     MyData obj1(101, "Alice Smith");
//     MyData obj2(102, "Bob Johnson");

//     // --- Writing objects to a file using fstream ---
//     fstream fileStream;
//     fileStream.open("data.bin", ios::out | ios::binary);

//     if (!fileStream.is_open()) {
//         cerr << "Error opening file for writing!" << endl;
//         return 1;
//     }

//     fileStream.write(reinterpret_cast<char*>(&obj1), sizeof(obj1));
//     fileStream.write(reinterpret_cast<char*>(&obj2), sizeof(obj2));

//     fileStream.close();
//     cout << "Objects written to data.bin" << endl;

//     // --- Reading objects from the file using fstream ---
//     MyData readObj1, readObj2; // Objects to store read data

//     fileStream.open("data.bin", ios::in | ios::binary);

//     if (!fileStream.is_open()) {
//         cerr << "Error opening file for reading!" << endl;
//         return 1;
//     }

//     fileStream.read(reinterpret_cast<char*>(&readObj1), sizeof(readObj1));
//     fileStream.read(reinterpret_cast<char*>(&readObj2), sizeof(readObj2));

//     fileStream.close();

//     cout << "\nObjects read from data.bin:" << endl;
//     readObj1.display();
//     readObj2.display();

//     return 0;
// }






// class MyData
// {
//     int id;
//     char name[20];
//     public:
//         MyData(int i=0,const char* n="Whatever") : id(i)
//         {
//             strcpy(name, n);
//         }

//         void display() {
//             cout<<"ID: "<<id<<"\nName: "<<name<<endl;
//         }

// };

// int main()
// {
//     MyData obj1(200, "Ali Jaan");
//     MyData obj2(6969, "Daddy Danyal");

//     fstream ob;

//     ob.open("data.bin", ios::out | ios::binary);

//     ob.write(reinterpret_cast<char*>(&obj1), sizeof(obj1));
//     ob.write(reinterpret_cast<char*>(&obj2), sizeof(obj2));

//     ob.close();

//     ob.open("data.bin", ios::in | ios::binary);

//     MyData he, de;

//     ob.read(reinterpret_cast<char*>(&he), sizeof(he));
//     ob.read(reinterpret_cast<char*>(&de), sizeof(de));

//     ob.close();

//     he.display();
//     de.display();



// }




#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 4, 6, 9};

    // Remove the last element
    v.pop_back();

    for (int i : v)
        cout << i << " ";
    return 0;
}