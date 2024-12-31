class Solution {
public:
    void wiggleSort(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<int>ans;
        int j=n-1;
        for(int i=(n-1)/2;i>-1;i--){
            ans.push_back(a[i]);
            if(j>(n-1)/2)
            ans.push_back(a[j]);
            j--;
        }
        a=ans;
    }
};