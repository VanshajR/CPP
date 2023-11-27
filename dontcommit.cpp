#include <iostream>
#include <algorithm> // for std::swap
#include <climits> // for INT_MAX

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void disp(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int heapExtractMax(int arr[], int& n) {
    if (n < 1) {
        return -1; // Indicates underflow
    }
    int max = arr[0];
    arr[0] = arr[n - 1];
    n = n - 1;
    maxHeapify(arr, n, 0);
    return max;
}

void insert(int arr[], int& n, int key) {
    n += 1;
    arr[n - 1] = key;

    int i = n - 1;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        std::swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int a[] = {4, 10, 3, 5, 1, 7, 8, 9, 2, 6};
    int n = sizeof(a) / sizeof(a[0]);
    disp(a, n);
    buildMaxHeap(a, n);
    std::cout << "\nMax heap:\n";
    disp(a, n);

    std::cout << "\nExtracting maximum elements:\n";
    int originalSize = n;
    while (n > 0) {
        int max = heapExtractMax(a, n);
        std::cout << max << " ";
    }
    std::cout << "\n";

    int b[] = {4, 10, 3, 5, 1, 7, 8, 9, 2, 6};
    int m = sizeof(b) / sizeof(b[0]);
    std::cout << "\nInserting elements:\n";
    for (int i = 0; i < m; i++) {
        insert(b, m, b[i]);
        std::cout << "Inserted: " << b[i] << ", Current Max: " << b[0] << "\n";
    }

    return 0;
}
