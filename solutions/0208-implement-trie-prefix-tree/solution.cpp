class Trie {
public:
    map<string,bool>v;
    Trie() {
        
    }
    
    void insert(string word) {
        v[word]=true;
    }
    
    bool search(string word) {
        if(v[word]==true){
            return true;
        }
        else{
            v[word]=false;
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        for(auto x:v){
            if(x.second==false){
                continue;
            }
            if(x.first.size()<prefix.size()){
                continue;
            }
            bool f=1;
            for(int i=0;i<prefix.size();i++){
                if(prefix[i]!=x.first[i]){
                    f=0;
                    break;
                }
            }
            if(f==1){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */