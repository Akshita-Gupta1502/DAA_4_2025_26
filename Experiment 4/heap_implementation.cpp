#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;

void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(heap[(i-1)/2], heap[i]);
        i = (i-1)/2;
    }
}

void insertElement() {
    if (heapSize == MAX) {
        cout << "Heap Overflow\n";
        return;
    }
    int val;
    cout << "Enter value to insert: ";
    cin >> val;
    heap[heapSize++] = val;
    heapifyUp(heapSize - 1);
    cout << "Inserted successfully\n";
}

void searchElement() {
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] == val) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found\n";
}

void deleteRoot() {
    if (heapSize == 0) {
        cout << "Heap is empty\n";
        return;
    }
    cout << "Deleted root element: " << heap[0] << endl;
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

void deleteAny() {
    if (heapSize == 0) {
        cout << "Heap is empty\n";
        return;
    }
    int val;
    cout << "Enter value to delete: ";
    cin >> val;
    int index = -1;
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] == val) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Element not found\n";
        return;
    }
    heap[index] = heap[heapSize - 1];
    heapSize--;
    heapifyUp(index);
    heapifyDown(index);
    cout << "Element deleted successfully\n";
}

void displayHeap() {
    if (heapSize == 0) {
        cout << "Heap is empty\n";
        return;
    }
    cout << "Heap elements: ";
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n---- MIN HEAP MENU ----\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete Root\n";
        cout << "4. Delete Any Element\n";
        cout << "5. Display Heap\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: insertElement(); break;
            case 2: searchElement(); break;
            case 3: deleteRoot(); break;
            case 4: deleteAny(); break;
            case 5: displayHeap(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
