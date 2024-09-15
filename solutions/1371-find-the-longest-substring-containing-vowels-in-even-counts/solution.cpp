class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>ans;
        for(auto x:s){
            if(x=='a'){
                ans.push_back(1);
            }
            else if(x=='e'){
                ans.push_back(2);
            }
            else if(x=='i'){
                ans.push_back(4);
            }
            else if(x=='o'){
                ans.push_back(8);
            }
            else if(x=='u'){
                ans.push_back(16);
            }
            else{
                ans.push_back(0);
            }
        }
        int c=0;
        vector<int>pre;
        vector<int>mp(32,-1);
        int anss=0;
        for(int i=0;i<s.size();i++){
            int x=ans[i];
            c^=x;
            pre.push_back(c);
            if(mp[c]==-1 && c!=0) mp[c]=i;
            anss=max(anss,i-mp[c]);
        }
        return anss;
    }
};