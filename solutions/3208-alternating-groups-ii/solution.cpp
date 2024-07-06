class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int c=2;
        int ans=0;
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i]!=colors[i-1] && colors[i]!=colors[i+1]){
               c++;
                if(c>k){
                    c=k;
                }
            }
            else{
                c=2;
            }
            if(c==k){
                ans++;
            }
        }
        return ans;
    }
};