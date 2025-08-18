#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    string name;
    string studentClass;
    char division;
    string bloodGroup;
    string contactAddress;
    string drivingLicense;
    string dateOfBirth;
    int rollNumber;
    long telephoneNumber;

    static int studentCount; // Static member to track student count

public:
    // Default Constructor
    Student()
        : name("Unknown"), studentClass("Unknown"), division('A'),
          bloodGroup("Unknown"), contactAddress("Unknown"),
          drivingLicense("Unknown"), dateOfBirth("01-01-2000"),
          rollNumber(0), telephoneNumber(0) {
        studentCount++;
    }

    // Parameterized Constructor
    Student(string n, string c, char d, string bg, string addr, string dl, string dob, int roll, long tel)
        : name(n), studentClass(c), division(d), bloodGroup(bg),
          contactAddress(addr), drivingLicense(dl), dateOfBirth(dob),
          rollNumber(roll), telephoneNumber(tel) {
        studentCount++;
    }

    // Copy Constructor
    Student(const Student& s)
        : name(s.name), studentClass(s.studentClass), division(s.division),
          bloodGroup(s.bloodGroup), contactAddress(s.contactAddress),
          drivingLicense(s.drivingLicense), dateOfBirth(s.dateOfBirth),
          rollNumber(s.rollNumber), telephoneNumber(s.telephoneNumber) {
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Function to input student details
    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Class: ";
        cin >> studentClass;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Address: ";
        cin.ignore(); // To handle trailing newline
        getline(cin, contactAddress);
        cout << "Enter Driving License: ";
        cin >> drivingLicense;
        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        cin >> dateOfBirth;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Telephone Number: ";
        cin >> telephoneNumber;
    }

    // Function to display student details
    void display() const {
        cout << left << setw(20) << name
             << setw(10) << studentClass
             << setw(10) << division
             << setw(15) << bloodGroup
             << setw(20) << contactAddress
             << setw(20) << drivingLicense
             << setw(15) << dateOfBirth
             << setw(10) << rollNumber
             << setw(15) << telephoneNumber << endl;
    }
};

// Initialize static member
int Student::studentCount = 0;

int main() {
    int numStudents;

    // Ask user for the number of students
    cout << "How many students would you like to add? ";
    cin >> numStudents;

    // Dynamically allocate an array of students
    Student* students = new Student[numStudents];

    // Input details for all students
    cout << "Enter details for " << numStudents << " students:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].input();
    }

    // Display student details in a tabular format
    cout << "\nStudent Details:\n";
    cout << left << setw(20) << "NAME"
         << setw(10) << "CLASS"
         << setw(10) << "DIVISION"
         << setw(15) << "BLOOD GROUP"
         << setw(20) << "ADDRESS"
         << setw(20) << "DRIVING LIC NO"
         << setw(15) << "DATE OF BIRTH"
         << setw(10) << "ROLL NO"
         << setw(15) << "TELEPHONE" << endl;
    cout << string(130, '=') << endl;

    for (int i = 0; i < numStudents; ++i) {
        students[i].display();
    }

    // Display total student count
    cout << "\nTotal Students Created: " << Student::getStudentCount() << endl;

    // Clean up dynamically allocated memory
    delete[] students;

    return 0;
}
