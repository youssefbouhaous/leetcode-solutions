class Trie{
    public:
    struct TreeNode{
        map<char,TreeNode*>children;
        bool is_end=false;
    };
    TreeNode* root;
    Trie() {
        root=new TreeNode();
    }

    void insert(string word) {
        TreeNode* cur=root;
        for(char ch:word){
            if(cur->children.find(ch)==cur->children.end()){
                cur->children[ch]=new TreeNode();
            }
            cur=cur->children[ch];
        }
        cur->is_end=true;
    }
    
    bool search(string word) {
        TreeNode* cur=root;
        for(char ch:word){
            if(cur->children.find(ch)==cur->children.end()){
                return false;
            }
            cur=cur->children[ch];
        }
        return cur->is_end;
    }
    
    vector<string> startsWith(string p) {
        vector<string>ans;
        TreeNode* cur=root;
        for(char ch:p){
            if(cur->children.find(ch)==cur->children.end()){
                return ans;
            }
            cur=cur->children[ch];
        }
        if(cur->is_end==true){
            ans.push_back(p);
        }
        for(auto x:cur->children){
            
            if(x.second!=nullptr){
                if(ans.size()==3){
                    break;
                }
                p.push_back(x.first);
                f(x.second,ans,p);
                p.pop_back();
            }
        }
        return ans;
    }
    void f(TreeNode* tmp,vector<string>&ans,string t){
        if(ans.size()==3){
            return;
        }
        if(tmp->is_end==true){
            ans.push_back(t);
        }
        for(auto x:tmp->children){
            if(x.second!=nullptr){
                t.push_back(x.first);
                f(x.second,ans,t);
                t.pop_back();
            }
        }
    }
};



class Solution {
    public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        vector<vector<string>>ans;
        Trie* t=new Trie();
        for(auto x:products){
            t->insert(x);
        }
        for(int i=1;i<=s.size();i++){
            ans.push_back(t->startsWith(s.substr(0,i)));
        }
        return ans;
    }
};