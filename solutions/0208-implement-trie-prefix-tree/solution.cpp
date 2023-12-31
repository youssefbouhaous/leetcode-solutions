class Trie {
public:
    struct TreeNode{
        unordered_map<char,TreeNode*>children;
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
    
    bool startsWith(string prefix) {
        TreeNode* cur=root;
        for(char ch:prefix){
            if(cur->children.find(ch)==cur->children.end()){
                return false;
            }
            cur=cur->children[ch];
        }
        return cur!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */