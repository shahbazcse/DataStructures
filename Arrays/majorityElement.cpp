// Link: https://leetcode.com/problems/majority-element/
// Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        int element=INT_MIN;
        int cnt=0;
        if(size==1) return nums[0];
        for(int i=0; i<size; i++){
            if(cnt==0){
                element=nums[i];
            }
            if(nums[i]==element){
                cnt++;
            }else cnt--;
        }
        return element;
    }
};

// Link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
// Moore's Voting Algorithm

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int element=0;
        int cnt=0;
        if(size==1) return a[0];
        for(int i=0; i<size; i++){
            if(cnt==0){
                element=a[i];
            }
            if(a[i]==element){
                cnt++;
            }else cnt--;
        }
        cnt=0;
        for(int i=0; i<size; i++){
            if(element==a[i]) cnt++;
        }
        if(cnt>size/2) return element;
        else return -1;
    }
};