Write a C++ program to simulate a simple job scheduling system using the queue data structure.
The program should:

1. Allow the user to add a job to the queue.

2. Allow the user to delete a job from the queue (dequeue operation).

3. Display all jobs currently in the queue.

4. Exit the program when the user chooses.

   
Use the queue container from the C++ Standard Template Library (STL).
Implement the following functions:
    -addJob(queue<string> &jobQueue, const string &job) – Adds a new job to the queue.
    -deleteJob(queue<string> &jobQueue) – Deletes the job at the front of the queue.
    -displayJobs(const queue<string> &jobQueue) – Displays all jobs in the queue.

Provide a menu-driven interface for the user to perform these operations.
