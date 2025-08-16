#include<iostream>
#include<string>
using namespace std;

class Publication {
public:
    string title;
    float price;

    // Default constructor to initialize data members
    Publication() {
        title = "";
        price = 0.0;
    }

    // Method to input title and price
    void setData() {
        cout << "\nEnter name of Publication: ";
        cin >> title;
        try {
            cout << "Enter price of item: ";
            cin >> price;
            if (price < 0) {
                throw price;  // Exception thrown if price is negative
            }
        }
        catch (float p) {
            cout << "An exception occurred! Resetting all values to default!" << endl;
            title = "";   // Resetting title
            price = 0.0;  // Resetting price
        }
    }
};

class Book : public Publication {
    int pgcnt;

public:
    // Constructor initializes page count to 0
    Book() {
        pgcnt = 0;
    }

    // Method to input book data, including title, price, and page count
    void bookData() {
        setData();  // Calls base class function to input title and price
        cout << "Enter number of pages in book:";
        try {
            cin >> pgcnt;
            if (pgcnt < 0) {
                throw pgcnt;  // Exception thrown if page count is negative
            }
        }
        catch (int p) {
            cout << "An exception occurred! Resetting all values to default!" << endl;
            title = "";   // Resetting title
            price = 0.0;  // Resetting price
            pgcnt = 0;    // Resetting page count
        }
    }

    // Method to display book data
    void displayBook() {
        cout << "\nPublication: " << title << "\nPrice: " << price << "\nPages: " << pgcnt << endl;
    }
};

class Tape : public Publication {
    float time;

public:
    // Constructor initializes time to 0
    Tape() {
        time = 0.0;
    }

    // Method to input tape data, including title, price, and playing time
    void tapeData() {
        setData();  // Calls base class function to input title and price
        cout << "Enter the number of minutes the tape plays (float): ";
        try {
            cin >> time;
            if (time < 0) {
                throw time;  // Exception thrown if time is negative
            }
        }
        catch (float t) {
            cout << "An exception occurred! Resetting all values to default!" << endl;
            title = "";  // Resetting title
            price = 0.0; // Resetting price
            time = 0.0;  // Resetting time
        }
    }

    // Method to display tape data
    void displayTape() {
        cout << "\nPublication: " << title << "\nPrice: " << price << "\nTime: " << time << endl;
    }
};

int main() {
    Book b;
    b.bookData();  // Calls bookData to input book details

    Tape t;
    t.tapeData();  // Calls tapeData to input tape details

    b.displayBook();  // Displays the book details
    t.displayTape();  // Displays the tape details

    return 0;
}
