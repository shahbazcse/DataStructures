// Link: https://www.codingninjas.com/codestudio/problems/n-queue-using-array_1170053

// Approach: 

#include <bits/stdc++.h> 
class NQueue{
    int *arr;
    int *front;
    int *rear;
    int *next;

    int freeSpot;
public:
    // Initialize your data structure.
    NQueue(int n, int s){
        
        front = new int[n];
        rear = new int[n];

        for(int i=0; i<n; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        
        arr = new int[s];
        next = new int[s];

        for(int i=0; i<s-1; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;

        freeSpot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freeSpot == -1) return false;

        int index = freeSpot;

        freeSpot = next[index];

        if(front[m-1] == -1){
            front[m-1] = index;
        }else{
            next[rear[m-1]] = index;
        }
        
        next[index] = -1;

        rear[m-1] = index;
        
        arr[index] = x;
        
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1] == -1) return -1;

        int index = front[m-1];

        front[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};