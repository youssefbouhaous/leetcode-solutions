class Solution {
public:
    int minSubArrayLen(int t, vector<int>& arr) {
        int l=0;
        int r=0;
        int s=0;
        int ans=0;
        while(l<=r && r<arr.size()){
            s+=arr[r];
            if(s>=t){
                if(ans==0)
                ans=r-l+1;
                else{
                    ans=min(ans,r-l+1);
                }
                s-=arr[l];
                l++;
                s-=arr[r];
            }
            else{
                r++;
            }
        }
        return ans;
    }
};