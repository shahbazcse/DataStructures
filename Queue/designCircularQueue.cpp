// Link: https://leetcode.com/problems/design-circular-queue/

// Approach: [TC: O(1) / SC: O(N)]

class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Constructor
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }

    // Destructor
    ~MyCircularQueue(){
        delete []arr;;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        if(front == -1){
            front = rear = 0;
        }else if(rear == size-1 && front != 0){
            rear = 0;
        }else rear++;

        arr[rear] = value;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        if(front == rear){
            front = rear = -1;
        }else if(front == size-1){
            front = 0;
        }else front ++;

        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1) return true;
        else return false;
    }
    
    bool isFull() {
        if(front == 0 && rear == size-1 || rear == front-1) return true;
        else return false;
    }
};