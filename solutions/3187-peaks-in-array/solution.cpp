class Solution {
public:
    vector<int> tree;
    int n;
    vector<int> numtmp;

    int sum(int k) {
        int s = 0;
        while (k >= 1) {
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }

    void add(int k, int x) {
        while (k <= n) {
            tree[k] += x;
            k += k & -k;
        }
    }

    void sup(int k, int x) {
        while (k <= n) {
            tree[k] -= x;
            k += k & -k;
        }
    }

    void update(int index, int val) {
        int old=numtmp[index];
        if(index==0 || index==n-1){
            numtmp[index] = val;
            if(index==0){
                if(n>2 && old>=numtmp[index+1]&& numtmp[index+1]>numtmp[index] && numtmp[index+1]>numtmp[index+2]){
                    add(index + 2, 1);
                }
                if(n>2 && old<numtmp[index+1]&& numtmp[index+1]<=numtmp[index] && numtmp[index+1]>numtmp[index+2]){
                    sup(index + 2, 1);
                }
            }
            if(index==n-1){
                if(n>2 && old>=numtmp[index-1]&& numtmp[index-1]>numtmp[index] && numtmp[index-1]>numtmp[index-2]){
                    add(index, 1);
                }
                if(n>2 && old<numtmp[index-1]&& numtmp[index-1]<=numtmp[index] && numtmp[index-1]>numtmp[index-2]){
                    sup(index, 1);
                }
            }
            return ;
        }
        numtmp[index] = val;
        if(!(old>numtmp[index+1] && old>numtmp[index-1])&& numtmp[index]>numtmp[index+1] && numtmp[index]>numtmp[index-1]){ 
            add(index + 1, 1);
        }
        if(!(numtmp[index]>numtmp[index+1] && numtmp[index]>numtmp[index-1]) && (old>numtmp[index+1] && old>numtmp[index-1])){
            sup(index + 1, 1);
        }
        if(index+2<n && old>=numtmp[index+1] && numtmp[index+1]>numtmp[index] && numtmp[index+1]>numtmp[index+2]){
            add(index + 2, 1);
        }
        if(index+2<n && old<numtmp[index+1] && numtmp[index+1]<=numtmp[index] && numtmp[index+1]>numtmp[index+2]){
            sup(index + 2, 1);
        }
        if(index-2>=0 && old>=numtmp[index-1] && numtmp[index-1]>numtmp[index] && numtmp[index-1]>numtmp[index-2]){
            add(index, 1);
        }
        if(index-2>=0 && old<numtmp[index-1] && numtmp[index-1]<=numtmp[index] && numtmp[index-1]>numtmp[index-2]){
            sup(index, 1);
        }
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        numtmp = nums;
        n = nums.size();
        tree = vector<int>(n + 1, 0);
        vector<int> ans;
        for (int i = 1; i < nums.size()-1; i++) {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
            add(i + 1, 1);
        }
        for (auto& x : queries) {
            if (x[0] == 1) {
                if(x[2]==x[1]){
                    ans.push_back(0);
                }
                else
                ans.push_back(max(sum(x[2]) - sum(x[1]+1),0));
            } else {
                update(x[1], x[2]);
            }
        }
        return ans;
    }
};