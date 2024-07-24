class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>colors;
        map<int,int>ele;
        vector<int>ans;
        int cnt=0;
        for(auto x:queries){
            if(ele[x[0]]==0){
                if(colors[x[1]]==0)
                cnt++;
                ele[x[0]]=x[1];
                colors[x[1]]++;
                ans.push_back(cnt);
            }
            else{
                    colors[ele[x[0]]]--;
                    if(colors[ele[x[0]]]==0){
                        cnt--;
                    }
                    if(colors[x[1]]==0)
                    cnt++;
                    colors[x[1]]++;
                    ele[x[0]]=x[1];
                    ans.push_back(cnt);
            }
        }
        return ans;
    }
};