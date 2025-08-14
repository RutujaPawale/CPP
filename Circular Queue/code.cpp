#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int* queue;   
    int front;  
    int rear;   
    int size; 
    int count; 

public:
   
    PizzaParlor(int max_orders) {
        size = max_orders;
        queue = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }

    ~PizzaParlor() {
        delete[] queue;
    }


    void placeOrder(int orderId) {
        if (count == size) {
            cout << "The pizza parlor is at full capacity. Cannot accept more orders!" << endl;
            return;
        }
        

        if (front == -1) {
            front = 0;
        }
        
        rear = (rear + 1) % size;

        queue[rear] = orderId;
        count++;
        cout << "Order " << orderId << " placed successfully." << endl;
    }

    void serveOrder() {
        if (count == 0) {
            cout << "No orders to serve." << endl;
            return;
        }
        
        cout << "Serving order " << queue[front] << "." << endl;
        
        front = (front + 1) % size;
        count--;
        

        if (count == 0) {
            front = -1;
            rear = -1;
        }
    }

    void displayOrders() {
        if (count == 0) {
            cout << "No orders in the queue." << endl;
            return;
        }

        cout << "Current orders in the queue: ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int M;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    PizzaParlor pizzaParlor(M);

    int choice, orderId;

    do {
        cout << "\nPizza Parlor System\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order ID to place: ";
                cin >> orderId;
                pizzaParlor.placeOrder(orderId);
                break;
            case 2:
                pizzaParlor.serveOrder();
                break;
            case 3:
                pizzaParlor.displayOrders();
                break;
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
