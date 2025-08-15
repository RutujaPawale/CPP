#include <iostream>
#include <list>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    struct QueueItem {
        T data;
        int priority;

        QueueItem(T d, int p) : data(d), priority(p) {}

        bool operator<=(const QueueItem& other) const {
            return priority >= other.priority;  // Higher priority first
        }
    };

    list<QueueItem> queue;

public:
    void enqueue(T data, int priority) {
        QueueItem newItem(data, priority);
        auto it = queue.begin();
        while (it != queue.end() && !(newItem <= *it)) {
            ++it;
        }
        queue.insert(it, newItem);
    }

    T dequeue() {
        if (queue.empty()) {
            throw runtime_error("Queue is empty!");
        }
        T highestPriorityItem = queue.front().data;
        queue.pop_front();
        return highestPriorityItem;
    }

    bool isEmpty() const {
        return queue.empty();
    }

    void display() const {
        if (queue.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (const auto& item : queue) {
            cout << "Data: " << item.data << ", Priority: " << item.priority << endl;
        }
    }
};

int main() {
    PriorityQueue<string> pq;
    int choice, priority;
    string task;

    while (true) {
        cout << "\n*** Priority Queue Menu ***\n";
        cout << "1. Enqueue a task\n";
        cout << "2. Dequeue a task\n";
        cout << "3. Display priority queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task name: ";
                cin.ignore();  // To clear the newline character from previous input
                getline(cin, task);
                cout << "Enter priority (higher number means higher priority): ";
                cin >> priority;
                pq.enqueue(task, priority);
                cout << "Task \"" << task << "\" with priority " << priority << " added to the queue.\n";
                break;
            case 2:
                try {
                    cout << "\nDequeued item: " << pq.dequeue() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                cout << "\nPriority Queue (Highest priority at the start):\n";
                pq.display();
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
