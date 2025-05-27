#include<iostream>
using namespace std;


// template<class T, class U, class V=double>
// class A {
// public:
//     T x;
//     U y;
//     V z;
//     static int count;
// };

// int main(){
//     A<int, int> a;
//     A<double, double> b;
//     cout << sizeof(a.x) << endl;
//     cout << sizeof(b.x) << endl;
//     return 0;
// }


// class Shape {
// public:
//     void draw() {
//         cout << "Drawing shape" << endl;
//     }
// };

// class Circle : public Shape {
// public:
//     void draw() {
//         cout << "Drawing circle" << endl;
//     }
// };

// void render(Shape* s) {
//     s->draw();
// }

// int main() {
//     Shape *obj = new Circle;
//     render(obj);
// }




// class Base {
// public:
//     static int count;
//     Base() { count++; }
//     virtual ~Base() { count--; }

//     static void printCount() {
//         cout << "Count: " << count << endl;
//     }
// };

// class Derived : public Base {
// public:
//     Derived() { count++; }
//     ~Derived() { count--; }
// };

// int Base::count = 0;

// int main() {
//     Base::printCount(); // 0
//     Base obj1;          // +1
//     Derived* obj2 = new Derived(); // +1 base +1 derived = +2
//     obj2->printCount(); // 3
//     delete obj2;        // -1 derived -1 base = -2
//     obj1.printCount();  // 1
// }



class Book {
private:
    string* title;
    bool borrowed;

public:
    Book(string t) : title(new string(t)), borrowed(false) { }

    Book(const Book& other) {
        title = new string(*other.title);
    }

    void operator=(Book other) {
        *title = *other.title;
    }

    void status() {
        cout << *title << ": " << borrowed << endl;
    }
};

int main() {
    Book b1("Book1");
    Book b2 = b1; // invokes copy constructor
    b2 = b1;      // invokes operator=
    b2.status();
}
