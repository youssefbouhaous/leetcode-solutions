class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>st;
        pair<int,int>init={0,0};
        st.insert(init);
        for(auto x:path){
            if(x=='N'){
                init.first++;
            }
            if(x=='S'){
                init.first--;
            }
            if(x=='E'){
                init.second++;
            }
            if(x=='W'){
                init.second--;
            }
            if(st.count(init)){
                return true;
            }
            st.insert(init);
        }
        return false;
    }
};