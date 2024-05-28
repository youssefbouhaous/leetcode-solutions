class NumArray {
public:
    vector<int>tree;
    int n;
    vector<int>numtmp;
    NumArray(vector<int>& nums) {
        tree.resize(nums.size()+1,0);
        numtmp=nums;
        n=nums.size();
        for(int i=0;i<nums.size();i++){
            add(i+1,nums[i]);
        }
    }
    int sum(int k) {
        int s = 0;
        while (k >= 1) {
            s += tree[k];
            k -= k&-k;
        }
        return s;
    }
    void add(int k, int x) {
        while (k <= n) {
            tree[k] += x;
            k += k&-k;
        }
    }
    void sup(int k, int x) {
        while (k <= n) {
            tree[k] -= x;
            k += k&-k;
        }
    }


    void update(int index, int val) {
        sup(index+1,numtmp[index]);
        numtmp[index]=val;
        add(index+1,val);
    }
    
    int sumRange(int left, int right) {
        return sum(right+1)-sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */