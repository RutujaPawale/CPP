#include <iostream>
using namespace std;

// Function template for selection sort
template<typename T>
void selectionSort(T A[], int len) {
    int i, j, min;  // Loop variables, 'min' stores the index of the smallest element
    T temp;  // Temporary variable to swap elements

    // Selection sort algorithm
    for (i = 0; i < len - 1; i++) {
        min = i;  // Assume the current element is the smallest
        // Find the index of the minimum element in the unsorted portion of the array
        for (j = i + 1; j < len; j++) {
            if (A[j] < A[min])
                min = j;  // Update 'min' if a smaller element is found
        }
        // Swap the found minimum element with the current element
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    // Output the sorted array
    cout << "Sorted Array: ";
    for (i = 0; i < len; i++) {
        cout << A[i] << " ";  // Print the sorted array elements
    }
    cout << endl;
}

int main() {
    int n, i;

    // Input and sort integer array
    cout << "\nEnter total number of integer elements: ";
    cin >> n;
    int A[n];  // Declare integer array
    cout << "Enter all integer elements: ";
    for (i = 0; i < n; i++) {
        cin >> A[i];  // Input elements into integer array
    }
    selectionSort(A, n);  // Call sort function for integer array

    // Input and sort float array
    cout << "\nEnter total number of float elements: ";
    cin >> n;
    float B[n];  // Declare float array
    cout << "Enter float elements: ";
    for (i = 0; i < n; i++) {
        cin >> B[i];  // Input elements into float array
    }
    selectionSort(B, n);  // Call sort function for float array

    return 0;
}
