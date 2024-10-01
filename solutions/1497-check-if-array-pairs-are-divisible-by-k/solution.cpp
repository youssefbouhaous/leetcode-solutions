class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            arr[i]=arr[i]%k;
            if(arr[i]<0){
                arr[i]+=k;
            }
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0 && mp[0]%2==1) return false;
            else if(arr[i]!=0 && mp[arr[i]]!=mp[k-arr[i]]) return false;
        }
        return true;
    }
};