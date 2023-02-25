// Link: https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

// Approach 1: Recursion - With 3 Rods [TC: O(2^N) / SC: O(N)]

// observe pattern: from -> aux && aux -> to

class Solution{
    public:
    int steps=0;
    long long toh(int N, int from, int to, int aux) {
        steps++;
        if(N==1){
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
            return steps;
        }
        
        // from -> aux
        toh(N-1,from,aux,to);
        
        // placing last disc from 'from' rod to 'to' rod
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        
        // aux -> to
        toh(N-1,aux,to,from);
    }
};

// Approach 2: Recursion - With 4 Rods [TC: O(2^(N/2)) / SC: O(N)]

// observe pattern: from -> aux1 && aux1 -> to , from -> aux2 && aux2 -> to

int steps=0; // Counter variable to keep track of the number of steps taken

// Recursive function to solve Tower of Hanoi problem with n disks
void toh(int n, char from, char to, char aux1, char aux2){
    if(n==0) return; // Base case: no disks to move

    steps++; // Increment step counter for the current move
    
    if(n==1){
        // Base case: only one disk to move
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        return;
    }
    
    // Move first n-2 disks to from 'from' rod to auxiliary rod 'aux1' (from -> aux1)
    toh(n-2,from,aux1,aux2,to);
    steps++; // Increment step counter for the current move
    
    // Move n-1th disk from 'from' rod to 'aux2' rod (from -> aux2)
    cout<<"move disk "<<n-1<<" from rod "<<from<<" to rod "<<aux2<<endl;

    // Move nth disk from 'from' rod to 'to' rod (placing last disc from 'from' rod to 'to' rod)
    cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;

    // Move n-1th disk from 'aux2' rod to 'to' rod (aux2 -> to)
    cout<<"move disk "<<n-1<<" from rod "<<aux2<<" to rod "<<to<<endl;
    
    // Move remaining n-2 disks from auxiliary rod 'aux1' to 'to' rod (aux1 -> to)
    toh(n-2,aux1,to,from,aux2);
    steps++; // Increment step counter for the current move
}

int main() {
    int n=4; // Number of disks to solve the problem for
   
    toh(n,'A','D','B','C'); // Call recursive function to solve the problem with 4 disks

    cout<<"Total steps: "<<steps<<endl; // Print total number of steps taken to solve the problem
    
    return 0;
}