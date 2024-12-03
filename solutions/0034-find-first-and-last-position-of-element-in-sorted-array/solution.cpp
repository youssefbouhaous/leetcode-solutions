class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int>ans={-1,-1};
        int n=arr.size();
        int l=0;int r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]==target){ans[0]=m;}
            if(arr[m]>=target) r=m-1;
            else l=m+1;
        }
        l=0;r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]==target){ans[1]=m;}
            if(arr[m]>target) r=m-1;
            else l=m+1;
        }
        if(ans[0]==-1){
            ans[0]=ans[1];
        }
        else if(ans[1]==-1) ans[1]=ans[0];
        return ans;
    }
};