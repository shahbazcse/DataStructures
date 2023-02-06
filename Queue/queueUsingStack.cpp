// Link: https://practice.geeksforgeeks.org/problems/queue-using-stack/1

// Approach: [TC: push: O(1) & pop: O(N) / SC: O(1)]

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        if(input.empty()) return -1;
        else{
            while(input.size()!=1){
                output.push(input.top());
                input.pop();
            }
            int val = input.top();
            input.pop();
            while(output.size()!=0){
                input.push(output.top());
                output.pop();
            }
            return val;
        }
    }
};