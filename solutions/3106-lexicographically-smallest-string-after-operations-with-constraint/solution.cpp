class Solution {
public:
    string getSmallestString(string s, int k) {
        string t=s;
        int n=s.size();
        for(int i=0;i<n;i++){
            int a=t[i];
            int b=t[i];
            int ak=k;
            int bk=k;
            while(ak && a!='a'){
                a--;
                ak--;
            }
            while(bk && b!='a'){
                if(b=='z'){
                    b='a';
                }
                else{
                b++;
                }
                bk--;
            }
            if(a=='a' && b=='a'){
                t[i]='a';
                k=max(ak,bk);
            }
            else if(b=='a'){
                
                t[i]='a';
                k=bk;
            }
            else{
                t[i]=a;
                k=ak;
            }
            //cout<<(char)a<<" "<<ak<<" "<<(char)b<<" "<<bk<<endl;
            if(!k){
                break;
            }
        }
        return t;
    }
};