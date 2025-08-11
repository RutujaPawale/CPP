#include <iostream>
#include <list>
#include <string>
using namespace std;
template <typename T>
class QueueItem {
public:
    T data;
    int priority;

    QueueItem(T d, int p) : data(d), priority(p) {}

    bool operator<=(const QueueItem& other) const {
        return this->priority >= other.priority;
    }
};

template <typename T>
class PriorityQueue {
private:
    list<QueueItem<T>> queueList;

public:
    void addItem(T data, int priority) {
        QueueItem<T> newItem(data, priority);
        typename list<QueueItem<T>>::iterator it;
        for (it = queueList.begin(); it != queueList.end(); ++it) {
            if (newItem <= *it) {
                break;
            }
        }
        queueList.insert(it, newItem);
        cout << "Added item: " << data << " with priority: " << priority << "\n";
    }

    void processItem() {
        if (!queueList.empty()) {
            QueueItem<T> item = queueList.front();
            cout << "Processing item: " << item.data << " with priority: " << item.priority << "\n";
            queueList.pop_front();
        } else {
            cout << "Queue is empty!\n";
        }
    }

    void displayQueue() const {
        if (queueList.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Current queue (in order of priority):\n";
        for (const auto& item : queueList) {
            cout << "Item: " << item.data << ", Priority: " << item.priority << "\n";
        }
    }
};

int main() {
    PriorityQueue<string> pq;
    int choice;
    do {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Delete Item\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string data;
                int priority;
                cout << "Enter data (string): ";
                cin >> data;
                cout << "Enter priority (integer): ";
                cin >> priority;
                pq.addItem(data, priority);
                break;
            }
            case 2:
                pq.processItem();
                break;
            case 3:
                pq.displayQueue();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
