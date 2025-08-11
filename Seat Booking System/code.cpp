#include <iostream>
#include <string>
using namespace std;

class Seat {
public:
    string seatNumber; // Store seat number as A-1, B-2, etc.
    bool isBooked;
    Seat* next;
    Seat* prev;

    Seat(string num) {
        seatNumber = num;
        isBooked = false;
        next = prev = nullptr;
    }
};

class Row {
public:
    Seat* head;
    Seat* tail;
    char rowID; // Row identifier (A, B, ..., J)

    Row(char id) {
        head = tail = nullptr;
        rowID = id;
    }

    void createRow() {
        for (int i = 1; i <= 7; i++) {
            string seatID = string(1, rowID) + "-" + to_string(i); // Generate seat ID like "A-1"
            Seat* newSeat = new Seat(seatID);
            if (!head) {
                head = tail = newSeat;
            } else {
                tail->next = newSeat;
                newSeat->prev = tail;
                tail = newSeat;
            }
        }
        tail->next = head; // Make it circular
        head->prev = tail;
    }

    void displayAvailableSeats() {
        Seat* temp = head;
        bool available = false;
        do {
            if (!temp->isBooked) {
                cout << temp->seatNumber << " ";
                available = true;
            }
            temp = temp->next;
        } while (temp != head);
        if (!available) {
            cout << "No available seats in this row.";
        }
        cout << endl;
    }

    bool bookSeat(string seatNum) {
        Seat* temp = head;
        do {
            if (temp->seatNumber == seatNum && !temp->isBooked) {
                temp->isBooked = true;
                cout << "Seat " << seatNum << " booked successfully." << endl;
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat " << seatNum << " is either already booked or doesn't exist." << endl;
        return false;
    }

    bool cancelBooking(string seatNum) {
        Seat* temp = head;
        do {
            if (temp->seatNumber == seatNum && temp->isBooked) {
                temp->isBooked = false;
                cout << "Seat " << seatNum << " booking cancelled." << endl;
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat " << seatNum << " is not booked or doesn't exist." << endl;
        return false;
    }
};

class CinemaxTheater {
public:
    Row* rows[10];

    CinemaxTheater() {
        char rowID = 'A';
        for (int i = 0; i < 10; i++) {
            rows[i] = new Row(rowID++); // Assign row IDs as "A", "B", ...
            rows[i]->createRow();
        }
    }

    void displayAvailableSeats() {
        for (int i = 0; i < 10; i++) {
            cout << "Row " << rows[i]->rowID << ": ";
            rows[i]->displayAvailableSeats();
        }
        cout << endl;
    }

    bool bookSeat(char rowID, int colNum) {
        if (rowID >= 'A' && rowID <= 'J') {
            int rowIndex = rowID - 'A'; // Convert rowID to row index (e.g., 'A' -> 0)
            string seatID = string(1, rowID) + "-" + to_string(colNum);
            return rows[rowIndex]->bookSeat(seatID);
        }
        cout << "Invalid row!" << endl;
        return false;
    }

    bool cancelBooking(char rowID, int colNum) {
        if (rowID >= 'A' && rowID <= 'J') {
            int rowIndex = rowID - 'A'; // Convert rowID to row index (e.g., 'A' -> 0)
            string seatID = string(1, rowID) + "-" + to_string(colNum);
            return rows[rowIndex]->cancelBooking(seatID);
        }
        cout << "Invalid row!" << endl;
        return false;
    }
};

int main() {
    CinemaxTheater theater;
    int choice;
    char rowID;
    int seatNum;

    while (true) {
        cout << "******** CINEMAX THEATER ********" << endl;
        cout << "1. Display available seats" << endl;
        cout << "2. Book a seat" << endl;
        cout << "3. Cancel booking" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                theater.displayAvailableSeats();
                break;
            case 2:
                cout << "Enter row letter (A-J): ";
                cin >> rowID;
                cout << "Enter seat number (1-7): ";
                cin >> seatNum;
                theater.bookSeat(rowID, seatNum);
                break;
            case 3:
                cout << "Enter row letter (A-J): ";
                cin >> rowID;
                cout << "Enter seat number (1-7): ";
                cin >> seatNum;
                theater.cancelBooking(rowID, seatNum);
                break;
            case 4:
                cout << "Thank you for using Cinemax Theater!" << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}
