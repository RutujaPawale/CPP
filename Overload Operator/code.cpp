#include <iostream>
using namespace std;
class Complex {
private:
    double real;  // Real part of the complex number
    double imag;  // Imaginary part of the complex number
public:
    // Default constructor
    Complex() : real(0), imag(0) {}
    // Constructor with parameters
    Complex(double r, double i) : real(r), imag(i) {}
    // Overload the + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    // Overload the * operator
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, 
                       real * other.imag + imag * other.real);
    }
    // Overload the << operator for output
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }
    // Overload the >> operator for input
    friend istream& operator>>(istream& is, Complex& c) {
        char sign, i;
        double r, im;
        is >> r >> sign >> im >> i; // e.g., "3 + 4i"
        c.real = r;
        c.imag = (sign == '-') ? -im : im;
        return is;
    }
};
// Sample usage
int main() {
    Complex c1; // Default constructor (0 + 0i)
    Complex c2(3, 4); // 3 + 4i
    Complex c3(1, -2); // 1 - 2i
    // Adding complex numbers
    Complex sum = c2 + c3;
    cout << "Sum: " << sum << endl; // Output: Sum: 4 + 2i
    // Multiplying complex numbers
    Complex product = c2 * c3;
    cout << "Product: " << product << endl; // Output: Product: 11 + 1i
    // Reading a complex number from input
    Complex c4;
    cout << "Enter a complex number (e.g., 3 + 4i): ";
    cin >> c4;
    cout << "You entered: " << c4 << endl;
    return 0;
}
  
02.	Develop a program in C++ to create a database of student’s information system containing the following information: Name, roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.
Code: 
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class Student {
public:
    string name;
    int rollNumber;
    string className;
    Student(string n, int r, string c) : name(n), rollNumber(r), className(c) {}
};
class StudentDatabase {
private:
    vector<Student> students;
public:
    void addStudent(const Student& student) {
        students.push_back(student);
   }
    Student getStudent(int rollNumber) {
        for (const auto& student : students) {
            if (student.rollNumber == rollNumber) {
                return student;
            }         }
        throw runtime_error("Student not found");
    }
    void updateStudent(int rollNumber, const Student& updatedStudent) {
        for (auto& student : students) {
            if (student.rollNumber == rollNumber) {
                student = updatedStudent;
                return;
            }         }
        throw runtime_error("Student not found");
    }
    void deleteStudent(int rollNumber) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it -> rollNumber == rollNumber) {
                students.erase(it);
                return;
            }        }
        throw runtime_error("Student not found");
    }
    void displayAllStudents() const {
        for (const auto& student : students) {
            cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber
                      << ", Class: " << student.className << endl;
        }    } };
int main() {
    StudentDatabase db;
    db.addStudent(Student("Alice", 1, "10A"));
    db.addStudent(Student("Bob", 2, "10B"));
    db.displayAllStudents();
    try {
        Student s = db.getStudent(1);
        cout << "Retrieved: " << s.name << endl;
        db.updateStudent(1, Student("Alice Updated", 1, "10A"));
        db.displayAllStudents();
        db.deleteStudent(2);
        db.displayAllStudents();
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
 
 
03.	Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.
Code: 
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
// Base class Publication
class Publication {
protected:
    string title;
    float price;
public:
    Publication(string t, float p) : title(t), price(p) {}
    virtual void display() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};
// Derived class Book
class Book : public Publication {
private:
    int pageCount;
public:
    Book(string t, float p, int pc) : Publication(t, p), pageCount(pc) {}
    void display() const override {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
}; 
class Tape : public Publication {
private:
    float playingTime;
public:
    Tape(string t, float p, float pt) : Publication(t, p), playingTime(pt) {}
    void display() const override {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};
Book getBookData() {
    string title;
    float price;
    int pageCount;
    cout << "Enter the title of the book:";
    getline(cin, title);
    cout << "Enter the price of the book: ";
    cin >> price;
    cout << "Enter the page count of the book: ";
    cin >> pageCount;
    cin.ignore(); // Clear the newline character from the input buffer
    return Book(title, price, pageCount);
}
// Function to get tape data
Tape getTapeData() {
    string title;
    float price;
    float playingTime;
    cout << "Enter the title of the tape: ";
    getline(cin, title);
    cout << "Enter the price of the tape: ";
    cin >> price;
    cout << "Enter the playing time of the tape (in minutes): ";
    cin >> playingTime;
    cin.ignore(); // Clear the newline character from the input buffer
    return Tape(title, price, playingTime);
}
int main() {
    try {
        Book book = getBookData();
        book.display();
    } catch (const exception& e) {
        cout << "An error occurred while entering book data. Setting all values to zero." << endl;
        Book book("", 0.0, 0);
        book.display();
    }     try {
        Tape tape = getTapeData();
        tape.display();     } catch (const exception& e) {
        cout << "An error occurred while entering tape data. Setting all values to zero." << endl;
        Tape tape("", 0.0, 0.0);
        tape.display();
    }     return 0; } 
 
04.	Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.
Code:
 
#include <iostream>  // For standard input and output
#include <fstream>   // For file operations
#include <string>    // For using strings
using namespace std;
int main() {
    // Step 1: Create an output file stream
    ofstream outputFile("example.txt");

    // Step 2: Check if the file opened successfully
    if (!outputFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1; // Exit with an error code
    }

    // Step 3: Write information to the file
    outputFile << "Hello, World!" << endl;
    outputFile << "This is a test file." << endl;

    // Step 4: Close the output file
    outputFile.close();

    // Step 5: Create an input file stream to read from the file
    ifstream inputFile("example.txt");

    // Step 6: Check if the file opened successfully
    if (!inputFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1; // Exit with an error code
    }

    // Step 7: Read information from the file and display it
    string line;
    while (getline(inputFile, line)) {
        cout << line << endl; // Print each line to the console
    }

    // Step 8: Close the input file
    inputFile.close();

    return 0; // Exit successfully
}
 
05.	Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
Code:
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
// Function to perform selection sort
template <typename T>
void selectionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function to print the array
template <typename T>
void printArray(const vector<T>& arr) {
    for (const T& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // Integer array example
    vector<int> intArray = {64, 25, 12, 22, 11};
    cout << "Original integer array: ";
    printArray(intArray);
    selectionSort(intArray);
    cout << "Sorted integer array: ";
    printArray(intArray);

    // Float array example
    vector<float> floatArray = {64.5, 25.1, 12.3, 22.4, 11.2};
    cout << "Original float array: ";
    printArray(floatArray);
    selectionSort(floatArray);
    cout << "Sorted float array: ";
    printArray(floatArray);

    return 0;
}

 
06.	Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container.
Code:
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <iomanip> 
using namespace std;  
// Step 1: Define a struct for personal records
struct PersonalRecord {
    string name;
    string dob; // Format: YYYY-MM-DD
    string telephone;

    // Constructor for easy initialization
    PersonalRecord(string n, string d, string t)
        : name(n), dob(d), telephone(t) {}
};
// Step 2: Create a vector container to store personal records
vector<PersonalRecord> records;

// Step 3: Implement a function to sort records by name
void sortRecordsByName() {
    sort(records.begin(), records.end(), [](const PersonalRecord &a, const PersonalRecord &b) {
        return a.name < b.name; // Sort by name in ascending order
    });
}
// Step 4: Implement a function to search for a record by telephone number
PersonalRecord* searchRecordByTelephone(const string &telephone) {
    for (auto &record : records) {
        if (record.telephone == telephone) {
            return &record; // Return pointer to the found record
        }
    }
    return nullptr; // Return nullptr if not found
}
// Step 5: Example usage
int main() {
    // Adding some records
    records.emplace_back("Alice Smith", "1990-05-15", "123-456-7890");
    records.emplace_back("Bob Johnson", "1985-10-20", "987-654-3210");
    records.emplace_back("Charlie Brown", "1992-03-30", "555-555-5555");

    // Sort records by name
    sortRecordsByName();

    // Display sorted records
    cout << "Sorted Records by Name:\n";
    for (const auto &record : records) {
        cout << setw(20) << record.name 
                  << setw(15) << record.dob 
                  << setw(15) << record.telephone << '\n';
    }

    // Search for a record by telephone number
    string searchTel = "987-654-3210";
    PersonalRecord* foundRecord = searchRecordByTelephone(searchTel);
    if (foundRecord) {
        cout << "\nRecord found:\n";
        cout << "Name: " << foundRecord->name 
                  << ", DOB: " << foundRecord->dob 
                  << ", Telephone: " << foundRecord->telephone << '\n';
    } else {
        cout << "\nRecord not found for telephone: " << searchTel << '\n';
    }

    return 0;
 
}
OR
 
06.	Write C++ program using STL for sorting and searching user defined records such as Item records (Item code, name, cost, quantity etc) using vector container.
Code:
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For sort and find_if
using namespace std;
// Step 1: Define the Item Record
struct Item {
    int code;          // Item code
    string name;  // Item name
    double cost;      // Item cost
    int quantity;     // Item quantity
};

// Step 2: Create a Vector of Item Records
vector<Item> items; // Vector to store item records

// Step 3: Implement Sorting
void sortItemsByCode(vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.code < b.code; // Sort in ascending order
    });
}
// Step 4: Implement Searching
Item* findItemByCode(const vector<Item>& items, int code) {
    auto it = find_if(items.begin(), items.end(), [code](const Item& item) {
        return item.code == code; // Compare item code
    });
    return (it != items.end()) ? &(*it) : nullptr; // Return pointer to item or nullptr
}
// Step 5: Test the Program
int main() {
    // Sample data
    items.push_back({101, "Apple", 0.50, 100});
    items.push_back({102, "Banana", 0.30, 150});
    items.push_back({103, "Orange", 0.80, 200});
    // Sort items by code
    sortItemsByCode(items);
   cout << "Sorted Items by Code:\n";
    for (const auto& item : items) {
        cout << "Code: " << item.code << ", Name: " << item.name 
                  << ", Cost: " << item.cost << ", Quantity: " << item.quantity << "\n";
    }
    // Search for an item
    int searchCode = 102;
    Item* foundItem = findItemByCode(items, searchCode);
    if (foundItem) {
        cout << "Found Item: " << foundItem->name << "\n";
    } else {
        cout << "Item not found.\n";
    }

    return 0;
}


07.	Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and returns the population of the state.
Code:
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    // Create a map to store state names and their populations
    map<string, long long> statePopulation;
    // Initialize the map with some Indian states and their populations
    statePopulation["Maharashtra"] = 112372972;
    statePopulation["Uttar Pradesh"] = 199812341;
    statePopulation["Bihar"] = 104099452;
    statePopulation["West Bengal"] = 91276115;
    statePopulation["Tamil Nadu"] = 72147030;
    statePopulation["Karnataka"] = 61095297;
    statePopulation["Gujarat"] = 60439692;
    statePopulation["Rajasthan"] = 68548437;
    statePopulation["Andhra Pradesh"] = 49577103;
    statePopulation["Odisha"] = 41974218;
    // Prompt the user to enter the name of a state
    string stateName;
    cout << "Enter the name of an Indian state: ";
    getline(cin, stateName);
    // Look up the population of the entered state
    auto it = statePopulation.find(stateName);
    if (it != statePopulation.end()) {
        cout << "The population of " << stateName << " is " << it->second << "." << endl;
    } else {
        cout << "State not found. Please check the name and try again." << endl;
    }
    return 0;
}
