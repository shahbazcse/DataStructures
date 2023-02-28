// Link: https://www.codechef.com/problems/CO319TSH

// Approach 1: Backtracking [TC: O(N) / SC: O(N)]

#include <iostream>
using namespace std;

// Recursive function to calculate the sum of first N natural numbers
int long long sum(int long long n) {
    if (n == 1) {
        // Base case: sum of first 1 natural number is 1
        return 1;
    } else {
        // Recursive case: sum of first N natural numbers is N + sum(N-1)
        return n + sum(n-1);
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int long long N;
        cin >> N;

        int long long s = sum(N); // Calculate the sum using the recursive function

        cout << s % 2 << endl;
    }

    return 0;
}

// Approach 2: One pass solution [TC: O(1) / SC: O(1)]

#include <iostream>
using namespace std;

int main() {
    int T; // number of test cases
    cin >> T; // read in number of test cases from standard input

    while (T--) { // execute loop T times
        int long long N, sum; // declare variables N and sum
        cin >> N; // read in N from standard input

        // calculate the sum of the first N natural numbers using the formula
        sum = N*(N+1)/2;

        // output the parity of the sum using the modulo operator
        // if the sum is even, modulo operator returns 0, otherwise it returns 1
        cout << sum % 2 << endl;
    }

    return 0; // indicate successful program execution
}