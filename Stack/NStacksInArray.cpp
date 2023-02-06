// Link: https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271

// Approach: [TC: O(1) / SC: O(S+N)]

#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;

    int n,s;

    int freeSpot;
public:
    // Constructor
    NStack(int N, int S)
    {
        n=N;
        s=S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // intialize top array
        for(int i=0; i<n; i++){
            top[i] = -1;
        }

        // intialize next array
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1; // update last index value of next array to -1

        // initialize freeSpot
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if(freeSpot == -1) return false;

        // find index
        int index = freeSpot;

        // insert element into array
        arr[index] = x;

        // update freeSpot
        freeSpot = next[index];

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check if stack is empty
        if(top[m-1] == -1) return -1;

        // update index
        int index = top[m-1];

        // update top
        top[m-1] = next[index];


        // update next array
        next[index] = freeSpot;

        // update freeSpot
        freeSpot = index;

        return arr[index];
    }
};