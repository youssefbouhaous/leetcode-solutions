class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(m!=n-1 && m!=0 && arr[m]>arr[m+1] && arr[m]>arr[m-1]){
                return m;
            }
            if(m==0){
                l=m+1;
            }
            else if(m==n-1){
                r=m-1;
            }
            else if(arr[m]>arr[m+1]){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return 0;
    }
};