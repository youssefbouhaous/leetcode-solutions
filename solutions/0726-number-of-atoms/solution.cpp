class Solution {
public:
    string countOfAtoms(string f) {
         //1 for element 2 for number 3 for parenthese
        vector<pair<string,int>>tokens; 
        string tmp;
        int n=f.size();
        for(int i=0;i<n;i++){
            tmp.push_back(f[i]);
            if(f[i]>='A' && f[i]<='Z'){
                if( (i+1==n || !(f[i+1]>='a' && f[i+1]<='z'))){
                    tokens.push_back({tmp,1});
                    tmp.clear();
                }
            }
            else if((f[i]>='a' && f[i]<='z')){
                tokens.push_back({tmp,1});
                tmp.clear();
            }
            else if((f[i]>='0' && f[i]<='9') && (i+1>n-1 || !(f[i+1]>='0' && f[i+1]<='9'))){
                tokens.push_back({tmp,2});
                tmp.clear();
            }
            else if(f[i]==')'|| f[i]=='('){
                tokens.push_back({tmp,3});
                tmp.clear();
            }
        }
        
        stack<map<string,int>>st;
        map<string,int>ans;
        st.push(ans);
        int i=0;
        map<string,int>last;
        n=tokens.size();
        while(i<n){
            if(tokens[i].first=="("){
                map<string,int>dt;
                st.push(dt);
                i++;
            }
            else if(tokens[i].first==")"){
                
                if(i+1<n && tokens[i+1].second==2){
                    for(auto& x:st.top()){
                        x.second*=stoi(tokens[i+1].first);
                    }
                    i++;
                }
                
                auto it=st.top();
                st.pop();
                for(auto x:it){
                    st.top()[x.first]+=x.second;
                }
                i++;
            }
            else{
                if(tokens[i].second==1){
                    if(i+1<n && tokens[i+1].second==2){
                        st.top()[tokens[i].first]+=stoi(tokens[i+1].first);
                        i++;
                    }
                    else{
                        st.top()[tokens[i].first]++;
                    }
                }
                i++;
            }
        }
        string ansf;

        for(auto x:st.top()){
            if(x.second>1)
            ansf+=x.first+to_string(x.second);
            else
            ansf+=x.first;
        }
        return ansf;
    }
};