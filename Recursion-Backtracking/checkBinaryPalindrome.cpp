// Link: https://practice.geeksforgeeks.org/problems/check-if-actual-binary-representation-of-a-number-is-palindrome0624/1

// Approach: [TC: O(LogN) / SC: O(LogN)]

class Solution{
public:
	void decToBin(long long int N, string &bin){
	    if(N==0) return;
	    
	    bin += string(1,N%2);
	    
	    decToBin(N/2,bin);
	}
	
	int binaryPalin (long long int N)
	{
	    string bin;
	    
	    decToBin(N,bin);
	    
	    string rev = bin;
	    
	    reverse(rev.begin(),rev.end());
	    
	    if(rev == bin) return 1;
	    else return 0;
	}
};