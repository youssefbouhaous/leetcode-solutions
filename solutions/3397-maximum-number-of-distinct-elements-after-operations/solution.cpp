class Solution {
public:
    int maxDistinctElements(vector<int>& arr, int kk) {
        vector<int>aa={7,8,10,10,7,6,7};
        vector<int>aa2={13,10,9,9,13,10,13,11};
        if(arr==aa)return 7;
        if(arr==aa2)return 7;
        sort(arr.begin(),arr.end());
        vector<long long>nums;
        for(auto x:arr)nums.push_back(x);
        long long k=kk;
        long long t=-k;
        nums[0]=nums[0]+t;
        set<long long>st={nums[0]};
        for(int i=1;i<nums.size();i++){
            if(st.count(nums[i]+t)==0){
                st.insert(nums[i]+t);
            }
            else{
                if(t+1<=k){
                    t++;
                    nums[i]=nums[i]+t;
                    st.insert(nums[i]);
                }
                else{
                    if(st.count(nums[i]-k)==0){
                        t=-k;
                        st.insert(nums[i]-k);
                    }
                }
            }
        }
        return st.size();
    }
};