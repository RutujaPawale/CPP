#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    
    Node(char value) {
        data = value;
        next = prev = nullptr;
    }
};

class BinaryNumber {
private:
    Node* head;
    Node* tail;
    
public:
    BinaryNumber() {
        head = tail = nullptr;
    }
    
    void insert(char value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
    
    void onesComplement() {
        Node* temp = head;
        while (temp) {
            temp->data = (temp->data == '0') ? '1' : '0';
            temp = temp->next;
        }
    }
    
    void twosComplement() {
        onesComplement();
        Node* temp = tail;
        bool carry = true;
        
        while (temp && carry) {
            if (temp->data == '0') {
                temp->data = '1';
                carry = false;
            } else {
                temp->data = '0';
            }
            temp = temp->prev;
        }
    }

    static BinaryNumber add(BinaryNumber& num1, BinaryNumber& num2) {
        Node* ptr1 = num1.tail;
        Node* ptr2 = num2.tail;
        BinaryNumber result;
        int carry = 0;
        
        while (ptr1 || ptr2 || carry) {
            int sum = carry;
            if (ptr1) {
                sum += (ptr1->data == '1') ? 1 : 0;
                ptr1 = ptr1->prev;
            }
            if (ptr2) {
                sum += (ptr2->data == '1') ? 1 : 0;
                ptr2 = ptr2->prev;
            }
            
            carry = sum / 2;
            result.insert((sum % 2) == 1 ? '1' : '0');
        }
        
        return result;
    }
    
    ~BinaryNumber() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    BinaryNumber num1, num2;
    string bin1, bin2;
    int choice;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter two binary numbers\n";
        cout << "2. Display binary numbers\n";
        cout << "3. Add two binary numbers\n";
        cout << "4. Compute 1's complement of both numbers\n";
        cout << "5. Compute 2's complement of both numbers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter first binary number: ";
                cin >> bin1;
                num1 = BinaryNumber();
                for (char bit : bin1) {
                    num1.insert(bit);
                }

                cout << "Enter second binary number: ";
                cin >> bin2;
                num2 = BinaryNumber();
                for (char bit : bin2) {
                    num2.insert(bit);
                }
                break;

            case 2:
                cout << "\nFirst Binary Number: ";
                num1.display();
                cout << "Second Binary Number: ";
                num2.display();
                break;

            case 3:
                {
                    BinaryNumber result = BinaryNumber::add(num1, num2);
                    cout << "\nSum of the two binary numbers: ";
                    result.display();
                }
                break;

            case 4:
                cout << "\n1's Complement of the first binary number: ";
                num1.onesComplement();
                num1.display();
                cout << "1's Complement of the second binary number: ";
                num2.onesComplement();
                num2.display();
                break;

            case 5:
                cout << "\n2's Complement of the first binary number: ";
                num1.twosComplement();
                num1.display();
                cout << "2's Complement of the second binary number: ";
                num2.twosComplement();
                num2.display();
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
