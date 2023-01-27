// Link: https://leetcode.com/problems/design-browser-history/

// Approach: Using Doubly LL [TC: O(steps)]

class BrowserHistory {
public:
    list<string> history; // Creating Doubly LL 
    list<string> :: iterator it; // Creating a pointer to navigate back and forth
    BrowserHistory(string homepage) {
        history.push_back(homepage); // Putting homepage as first page
        it=history.begin(); // Pointing iterator to homepage
    }
    
    void visit(string url) {
        // Finding the next page after current page
        list<string> :: iterator del=it;
        del++; // Moving pointer to next page

        // Deleting from next page to last page(end of list)
        history.erase(del,history.end());
        
        // Adding new page as next page
        history.push_back(url);
        it++; // Moving pointer to new page
    }
    
    string back(int steps) {
        // Moving back 'steps' times till the first page
        while(it!=history.begin() && steps--){
            it--;
        }
        return *it; // Returning the desired page or first page if (steps > pointer of first page)
    }
    
    string forward(int steps) {
        // Moving forward 'steps' times till the last page
        // --history.end() indicates the last page, as history.end() means last page+1
        while(it!=(--history.end()) && steps--){
            it++;
        }
        return *it; // Returning the desired page or last page if (steps > pointer of last page)
    }
};