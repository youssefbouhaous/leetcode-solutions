class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int a=0;
        int b=0;
        int c=0;
        
        int[] cc = new int[n+m];
        while(a!=m && b!=n){
            if(nums1[a]<nums2[b]){
                cc[c]=nums1[a];
                a++;
            }
            else{
                cc[c]=nums2[b];
                b++;
            }
            c++;
        }
        if(a==m){
            for(int i=b;i<n;i++){
                cc[c]=nums2[i];
                c++;
            }
        }
        else if(b==n){
            for(int i=a;i<m;i++){
                cc[c]=nums1[i];
                c++;
            }
        }
        for(int i=0;i<n+m;i++){
            nums1[i]=cc[i];
        }
    }
}