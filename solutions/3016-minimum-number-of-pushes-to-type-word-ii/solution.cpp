class Solution {
public:
    int minimumPushes(string word) {
        int k=0;
        int ans=0;
        map<int,int>d;
        for(auto x:word){
            d[x]++;
        }
        multiset<int>st;
        for(auto x:d){
            st.insert(-x.second);
            //cout<<x.second;
        }
        for(auto x:st){
            k++;
            if(k<=8){
                ans+=-x;
            }
            else if(k<=16){
                ans+=-2*x;
            }
            else if(k<=24){
                ans+=-3*x;
            }
            else{
                ans+=-4*x;
            }
        }
        return ans;
    }
};