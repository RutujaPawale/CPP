#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Step 1: Create an output file and write information to it
    ofstream outFile;  // Open the file in output mode
    outFile.open("data.txt", ios::app);  // Open in append mode
    string dataToWrite;

    while (true) {
        cout << "Enter 1 to add data or 0 to stop: ";
        int ch;
        cin >> ch;

        if (ch == 1) {
            cin.get();  // Clear buffer
            cout << "Enter data you want to add: ";
            getline(cin, dataToWrite);
            outFile << dataToWrite << endl;  // Write to the file
        } else if (ch == 0) {
            cout << "\nClosing file." << endl;
            break;
        } else {
            cout << "Invalid choice. Enter 1 to add or 0 to stop." << endl;
        }
    }
    outFile.close();  // Close the file

    // Step 2: Open the file in input mode to read information
    ifstream inFile;
    inFile.open("data.txt", ios::in);  // Open in read mode
    if (!inFile) {
        cout << "Error: File could not be opened!" << endl;
        return 1;
    }

    cout << "\nReading from the file:" << endl;
    while (getline(inFile, dataToWrite)) {  // Read each line
        cout << dataToWrite << endl;  // Display the line
    }

    inFile.close();  // Close the file
    return 0;
}























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
