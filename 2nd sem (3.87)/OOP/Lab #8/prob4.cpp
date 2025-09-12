#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string id;
    bool available;
public:
    Media(string t, string i) {
        title = t;
        id = i;
        available = true;
    }
    
    bool borrow() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }
    
    void returnMedia() {
        available = true;
    }
    
    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }
};

class Book : public Media {
private:
    string author;
    string isbn;
public:
    Book(string t, string i, string a, string isbn) : Media(t, i) {
        author = a;
        this->isbn = isbn;
    }
    
    void display() override {
        Media::display();
        cout << "Type: Book" << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;
    string date;
public:
    Magazine(string t, string i, int issue, string d) : Media(t, i) {
        issueNumber = issue;
        date = d;
    }
    
    void display() override {
        Media::display();
        cout << "Type: Magazine" << endl;
        cout << "Issue: " << issueNumber << endl;
        cout << "Date: " << date << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
public:
    DVD(string t, string i, string dir, int dur) : Media(t, i) {
        director = dir;
        duration = dur;
    }
    
    void display() override {
        Media::display();
        cout << "Type: DVD" << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

int main() {
    Book b1("Harri puttar", "B001", "Just kidding Rowling", "978-3-16-148410-0");
    Magazine m1("Time", "M001", 45, "May 2023");
    DVD d1("Inception", "D001", "Christopher Nolan", 148);
    
    b1.display();
    cout << "-----------" << endl;
    
    m1.borrow();
    m1.display();
    cout << "-----------" << endl;
    
    d1.display();
    
    return 0;
}