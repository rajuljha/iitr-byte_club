#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int *arr;
public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        arr = new int[size];
    }

    void enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        }
        else {
            int i;
            if (front <= rear) {
                for (i = rear; i >= front; i--) {
                    if (value > arr[i]) {
                        arr[i + 1] = arr[i];
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                for (i = rear; i >= 0; i--) {
                    if (value > arr[i]) {
                        arr[i + 1] = arr[i];
                    }
                    else {
                        break;
                    }
                }
                for (i = size - 1; i >= front; i--) {
                    if (value > arr[i]) {
                        arr[i + 1] = arr[i];
                    }
                    else {
                        break;
                    }
                }
            }
            arr[i + 1] = value;
            rear++;
        }
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return data;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Elements in the queue are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the circular queue: ";
    cin >> size;
    CircularQueue cq(size);
    do {
        cout << "Enter your choice:\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exiting the program" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}
