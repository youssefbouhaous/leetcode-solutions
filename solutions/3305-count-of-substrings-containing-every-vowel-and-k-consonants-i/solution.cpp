class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n=word.size();
        int ans=0;
        vector<vector<int>>v(5,vector<int>(n+1));
        vector<int>c(n+1);
        set<char>st={'a', 'e', 'i', 'o','u'};
        for(int i=0;i<n;i++){
            if(word[i]=='a'){
                v[0][i+1]=v[0][i]+1;
                v[1][i+1]=v[1][i];
                v[2][i+1]=v[2][i];
                v[3][i+1]=v[3][i];
                v[4][i+1]=v[4][i];
                c[i+1]=c[i];
            }
            else if(word[i]=='e'){
                v[0][i+1]=v[0][i];
                v[1][i+1]=v[1][i]+1;
                v[2][i+1]=v[2][i];
                v[3][i+1]=v[3][i];
                v[4][i+1]=v[4][i];
                c[i+1]=c[i];
            }
            else if(word[i]=='i'){
                v[0][i+1]=v[0][i];
                v[1][i+1]=v[1][i];
                v[2][i+1]=v[2][i]+1;
                v[3][i+1]=v[3][i];
                v[4][i+1]=v[4][i];
                c[i+1]=c[i];
            }
            else if(word[i]=='o'){
                v[0][i+1]=v[0][i];
                v[1][i+1]=v[1][i];
                v[2][i+1]=v[2][i];
                v[3][i+1]=v[3][i]+1;
                v[4][i+1]=v[4][i];
                c[i+1]=c[i];
            }
            else if(word[i]=='u'){
                v[0][i+1]=v[0][i];
                v[1][i+1]=v[1][i];
                v[2][i+1]=v[2][i];
                v[3][i+1]=v[3][i];
                v[4][i+1]=v[4][i]+1;
                c[i+1]=c[i];
            }
            else{
                v[0][i+1]=v[0][i];
                v[1][i+1]=v[1][i];
                v[2][i+1]=v[2][i];
                v[3][i+1]=v[3][i];
                v[4][i+1]=v[4][i];
                c[i+1]=c[i]+1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool f=true;
                for(int l=0;l<5;l++){
                    //cout<<"v:"<<(v[l][j+1]-v[l][i])<<" ";
                    if(v[l][j+1]-v[l][i]==0){
                        f=false;
                        break;
                    }
                }
                //cout<<"c:"<<(c[j+1]-c[i])<<endl;
                if(f && (c[j+1]-c[i]==k)){
                    ans++;
                }
            }
        }
        return ans;
    }
};