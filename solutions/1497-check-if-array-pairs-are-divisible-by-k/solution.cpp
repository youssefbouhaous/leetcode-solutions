class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>d;
        for(int i=0;i<n;i++){
            arr[i]=(arr[i])%k;
            if(arr[i]<0) arr[i]+=k;
            d[arr[i]]++;
        }
        if(d[0]%2==1) return false;
        for(auto x:arr){
            if(x!=0 && d[k-x]!=d[x]){
                return false;
            }
        }
        return true;
    }
};