// Link: https://www.geeksforgeeks.org/mutual-recursion-example-hofstadter-female-male-sequences/

// Approach: Recursion [TC: O(N) / SC: O(N)]

// Function declarations
void functionA(int n);
void functionB(int n);

// Function B implementation
void functionB(int n) {
    // Base case
    if (n == 0) {
        return;
    }
    // Print the current value of n
    printf("%d ", n);
    // Call functionA with n - 1
    functionA(n - 1);
}

// Function A implementation
void functionA(int n) {
    // Base case
    if (n == 0) {
        return;
    }
    // Print the current value of n
    printf("%d ", n);
    // Call functionB with n - 1
    functionB(n - 1);
}

// Main function
int main() {
    // Call functionA with initial value 5
    functionA(5);
    return 0;
}