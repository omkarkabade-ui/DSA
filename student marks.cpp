//experiment 10
#include <iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        MaxHeapify(a, largest, n);
    }
}

void MinHeapify(int a[], int i, int n) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        MinHeapify(a, smallest, n);
    }
}

void Build_MaxHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MaxHeapify(a, i, n);
}

void Build_MinHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(a, i, n);
}

void MaxHeapSort(int a[], int n) {
    Build_MaxHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        MaxHeapify(a, 0, i);
    }
}

void MinHeapSort(int a[], int n) {
    Build_MinHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        MinHeapify(a, 0, i);
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Sort in ascending order using max heap
    MaxHeapSort(arr, n);
    cout << "\nSorted Marks (Ascending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    int min = arr[0];

    // Sort in descending order using min heap
    MinHeapSort(arr, n);
    cout << "\nSorted Marks (Descending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    int max = arr[0];

    cout << "\nMaximum Marks: " << max << "\nMinimum Marks: " << min << endl;

    return 0;
}
