class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto x:nums){
            q.push(x);        
        }
        k--;
        while(k--){
            q.pop();
        }
        return q.top();
    }
};