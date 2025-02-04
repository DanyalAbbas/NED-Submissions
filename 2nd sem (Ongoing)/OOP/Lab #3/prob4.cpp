#include <iostream>
using namespace std;

class bookType
{
        string title;
        string author[4];
        string publisher;
        int numAuthors;
        int ISBN;
        int price;
        int no_of_copies; 
    public:
        bookType(string t, string a[], string p, int i, int pr, int n, int no)
        {
            title = t;
            for (int i = 0; i < 4; i++)
                author[i] = a[i];
            publisher = p;
            ISBN = i;
            price = pr;
            no_of_copies = n;
            numAuthors = no;

        }
         
        // setters
        void setTitle(string t) {title = t;}
        void setPublisher( string pub ) {publisher = pub;}
        void setISBN(int i) {ISBN = i;}
        void setPrice(int p) {price = p;}
        void setNumCopiesInStock( int copies) {no_of_copies = copies;}
        void setAuthors( string auth[], int numAuth)
        {
            numAuthors = min(numAuth, 4);
            for ( int i = 0 ; i < numAuthors ; i++ )
                {author[i] = auth[i];}
        }

        // getters
        string getTitle( ) {return title;}
        string* getAuthors( ) {return author;} 
        string getPublisher( ) {return publisher;}
        int getISBN( ) {return ISBN;} 
        int getPrice( ) {return price;}
        int getNumCopiesInStock( ) {return no_of_copies;}
        int getNumAuthors( )  {return numAuthors;}


        void showBookInfo( )
        {
            cout<<ISBN<<". "<<title<<" By ";
            for (int i = 0; i < numAuthors-1; i++) {cout<<author[i]<<", ";}
            cout<<author[numAuthors-1]<<endl;
            cout<<"Published by "<<publisher<<endl;
            cout<<"Stock available : "<<no_of_copies<<endl;
            cout<<"Price : "<<price<<endl;
        }
        void searchByTitle(string t)
        {
            if(title == t) 
            {
                cout <<t<< " Book found . Details are : \n" ;
                showBookInfo();
            }
        }
        void searchByISBN(int i)
        {
            if(ISBN == i) 
            {
                cout <<ISBN<< " Book found . Details are : \n" ;
                showBookInfo();
            }
        }
        void updateStock(int newStock) {no_of_copies = newStock;}


};

int main()
{
    bookType* books[100] = { nullptr } ;
    int bookCount = 0;

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add a new book\n";
        cout << "2. Show all books\n";
        cout << "3. Search by title\n";
        cout << "4. Search by ISBN\n";
        cout << "5. Update stock of a book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        fflush(stdin);
        switch (choice) {
        case 1:
            if (bookCount < 100) {
                cin.ignore(); // clear input buffer
                string title;
                cout << "Title: ";
                fflush(stdin);
                cin>>title;
                
                int numAuthors;
                cout << "Number of authors: ";
                fflush(stdin);
                cin >> numAuthors;
                if (numAuthors < 0 || numAuthors > 100) {
                    cout << "Invalid number of authors. Maximum allowed authors: " << 100 << endl;
                    break;
                }
                string authors[4];
                fflush(stdin);
                for (int i = 0; i < 4; i++)
                {
                    cout << "Author " << i + 1 << ": ";
                    getline(cin, authors[i]);
                    fflush(stdin);
                }

                string publisher;
                cout << "Publisher: ";
                fflush(stdin);
                getline(cin, publisher);
                int isbn;
                cout << "ISBN: ";
                fflush(stdin);
                cin>>isbn;
                int price;
                cout << "Price: ";
                fflush(stdin);
                cin >> price;
                int numCopiesInStock;
                cout << "Number of copies in stock: ";
                fflush(stdin);
                cin >> numCopiesInStock;

                books[bookCount++] = new bookType(title, authors, publisher, isbn, price, numCopiesInStock, numAuthors);
            }
            else {
                cout << "Maximum number of books reached!" << endl;
            }
            break;
        case 2:
            cout << "\n===== ALL BOOKS =====\n";
            for (int i = 0; i < bookCount; i++) {
                cout << "Book " << i + 1 << ":\n";
                books[i] -> showBookInfo();
            }
            break;
        case 3:
            if (bookCount > 0) {
                cin.ignore(); // clear input buffer
                string searchTitle;
                cout << "Enter the title to search: ";
                getline(cin, searchTitle);
                for (int i = 0; i < bookCount; i++) {
                    books[i]->searchByTitle(searchTitle);
                }
            }
            else {
                cout << "No books available to search!" << endl;
            }
            break;
        case 4:
            if (bookCount > 0) {
                cin.ignore(); // clear input buffer
                int searchISBN;
                cout << "Enter the ISBN to search: ";
                cin>>searchISBN;
                for (int i = 0; i < bookCount; i++) {
                    books[i]->searchByISBN(searchISBN);
                }
            }
            else {
                cout << "No books available to search!" << endl;
            }
            break;
        case 5:
            if (bookCount > 0) {
                int bookIndex, newStock;
                cout << "Enter the index of the book to update stock: ";
                cin >> bookIndex;
                if (bookIndex >= 0 && bookIndex < bookCount) {
                    cout << "Enter the new stock: ";
                    cin >> newStock;
                    books[bookIndex]->updateStock(newStock);
                    cout << "Stock updated successfully!" << endl;
                }
                else {
                    cout << "Invalid book index!" << endl;
                }
            }
            else {
                cout << "No books available to update stock!" << endl;
            }
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    // Free memory allocated to book objects
    for (int i = 0; i < bookCount; i++) {
        delete books[i];
    }
}