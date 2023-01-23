// Link: https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// Approach: [TC: O(N)]

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        
        
        Node* start = head;
        int s=0;
        
        int e=0;
        Node* end = head;
        while(end->next){
            end=end->next;
            e++;
        }
        
        while(s<e){
            if((start->data)+(end->data)==target){
                ans.push_back({start->data,end->data});
                
                start=start->next;
                s++;
            }
            if((start->data)+(end->data)>target){
                end=end->prev;
                e--;
            }else{
                start=start->next;
                s++;
            }
        }
        return ans;
    }
};