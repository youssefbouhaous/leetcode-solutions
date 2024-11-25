class Solution {
    void mergeArr(vector<int>&a,int l,int m,int r){
        int n=r-l+1;
        vector<int>b(n);
        int l1,r1,l2,r2;
        l1=l;
        r1=m;
        l2=m+1;
        r2=r;
        for(int i=0;i<n;i++){
            if(l1>r1) {b[i]=a[l2];l2++;} 
            else if(l2>r2) {b[i]=a[l1];l1++;}
            else if(a[l1]>a[l2]){b[i]=a[l2];l2++;}
            else{ b[i]=a[l1];l1++;} 
        }
        for(int i=0;i<n;i++){
            a[l]=b[i];l++;
            //cout<<a[l]<<" ";
        }
        //cout<<endl;
    }
    void mergeSort(vector<int>&nums,int l,int r){
        if(l>=r) return ;
        int m=(l+r)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,r);
        mergeArr(nums,l,m,r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};