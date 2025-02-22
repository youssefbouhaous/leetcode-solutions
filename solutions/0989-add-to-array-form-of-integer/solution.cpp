class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        vector<int>b;
        while(k){
            b.push_back(k%10);
            k/=10;
        }
        reverse(num.begin(),num.end());
        int r=0;
        int n=max(num.size(),b.size());
        for(int i=0;i<n;i++){
            if(i>=b.size()&&i>=num.size())break;
            if(i<b.size()&&i<num.size()){
            ans.push_back((num[i]+b[i])+r);
            }
            else if(i<b.size())ans.push_back(b[i]+r);
            else if(i<num.size())ans.push_back(num[i]+r);

            r=ans.back()/10;
            ans[(int)ans.size()-1]=ans[(int)ans.size()-1]%10;
        }
        ans.push_back(r);
        if(ans.back()==0)ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};