class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector <long long> ans;
        ans.push_back(A*B/__gcd(A,B));
        ans.push_back(__gcd(A,B));
        return ans;
    }
};