class Solution {
public:
    int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
        set<pair<int,int>>st;
        for(int i=0;i<a.size();i++){
            st.insert({-(a[i]-b[i]),i});
        }
        int i=0;
        int ans=0;
        for(auto x:st){
            if(i<k){
                ans+=a[x.second];
            }
            else{
                ans+=b[x.second];
            }
            i++;
        }
        return ans;
    }
};