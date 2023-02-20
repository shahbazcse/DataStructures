// Link: https://practice.geeksforgeeks.org/problems/reverse-a-string/1

// Approach: Recursion [TC: O(|S|) / SC: O(1)]

void reverse(string &str, int s){
    if(s>=str.length()/2) return;
    
    swap(str[s],str[str.length()-s-1]);
    s++;
    
    reverse(str,s);
}

string reverseWord(string str){
    int s = 0;
    reverse(str,s);
    return str;
}