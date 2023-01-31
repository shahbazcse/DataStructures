// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

// Approach 1: Brute Force [TC: O(NLogN)]

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;

        for(auto i:nums1) temp.push_back(i);
        for(auto i:nums2) temp.push_back(i);

        sort(temp.begin(),temp.end());
        int size=temp.size();

        if(size%2==0){
            int n=size/2;
            return (temp[n-1]+temp[n])/2.0;
        }else return temp[size/2];
    }
};

// Approach 2: Binary Search [TC: O(LogN)]

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low=0;
        int high=n1;

        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=(n1+n2+1)/2-cut1;

            int left1= cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2= cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int right1= cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2= cut2 == n2 ? INT_MAX : nums2[cut2];

            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2==0){
                    double median = (max(left1,left2) + min(right1,right2))/2.0;
                    return median;
                }else{
                    double median = max(left1,left2);
                    return median;
                }
            }else if(left1>right2) high=cut1-1;
            else low=cut1+1;
        }
        return 0.0;
    }
};