// Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/tug-of-war-official/ojquestion

// Approach: Backtracking [TC: O(2^N) / SC: O(N)]

// This program finds two subsets of an array such that the absolute difference between their sums is minimized.
#include <bits/stdc++.h>
using namespace std;

int mini = INT_MAX; // Initialize the minimum difference between the two subsets to maximum integer value

// Recursive function to find the two subsets with minimum difference
void solve(vector<int> arr, vector<vector<int>> &ans, int idx, vector<int> &sub1, vector<int> &sub2, int sum1, int sum2){
    // Base case: if all elements of the array have been considered
    if (idx == arr.size()){
        // If the difference between the two subsets is less than the current minimum difference
        if (abs(sum1 - sum2) < mini){                            
            // Update the minimum difference
            mini = abs(sum1 - sum2);
            
            // Remove the previously stored subsets from the answer vector
            if (ans.size() > 0)
            {
                ans.pop_back();
                ans.pop_back();
            }

            // Store the current subsets in the answer vector
            ans.push_back(sub1);
            ans.push_back(sub2);
        }
        return;
    }

    // If subset 1 can still have more elements
    if (sub1.size() < (arr.size() + 1) / 2)
    {                                                                
        // Add the current element to subset 1 upto n/2
        sub1.push_back(arr[idx]);                                    
        
        // Add current element to sum1 and make recursive call
        solve(arr, ans, idx + 1, sub1, sub2, sum1 + arr[idx], sum2);
        
        // Remove the current element from subset 1
        sub1.pop_back();                                             
    }

    // If subset 2 can still have more elements
    if (sub2.size() < (arr.size() + 1) / 2)
    {                                                                
        // Add the current element to subset 2 upto n/2
        sub2.push_back(arr[idx]);                                    
        
        // Add current element to sum2 and make recursive call
        solve(arr, ans, idx + 1, sub1, sub2, sum1, sum2 + arr[idx]);
        
        // Remove the current element from subset 2
        sub2.pop_back();                                             
    }
}

int main()
{
    // Initialize the input array
    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; 
    
    // Vector to store the answer subsets
    vector<vector<int>> ans;                                        
    
    // Vector to store subset 1
    vector<int> sub1;                                               
    
    // Vector to store subset 2
    vector<int> sub2;                                               
    
    // Call the recursive function with initial parameters
    solve(arr, ans, 0, sub1, sub2, 0, 0);                           

    // Print the answer subsets
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}