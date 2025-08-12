#include <iostream>
#include <queue>
#include <string>
using namespace std;

void addJob(queue<string> &jobQueue, const string &job) {
    jobQueue.push(job);
    cout << "Job added: " << job << endl;
}

void deleteJob(queue<string> &jobQueue) {
    if (!jobQueue.empty()) {
        cout << "Job deleted: " << jobQueue.front() << endl;
        jobQueue.pop();
    } else {
        cout << "Queue is empty, no job to delete!" << endl;
    }
}

void displayJobs(const queue<string> &jobQueue) {
    if (jobQueue.empty()) {
        cout << "Job queue is empty." << endl;
    } else {
        queue<string> tempQueue = jobQueue;
        cout << "Jobs in the queue:" << endl;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }
}

int main() {
    queue<string> jobQueue;
    int choice;
    string job;

    do {
        cout << "\n--- Job Queue Menu ---" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the job name: ";
                cin >> job;
                addJob(jobQueue, job);
                break;
            case 2:
                deleteJob(jobQueue);
                break;
            case 3:
                displayJobs(jobQueue);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
