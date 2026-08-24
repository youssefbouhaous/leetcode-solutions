class WordDictionary {
    class Node{
        boolean ter;
        Node[] children = new Node[26];
    }
    Node head;
    public WordDictionary() {
        head = new Node();
    }
    
    public void addWord(String word) {
        int n = word.length();
        Node cur = head;
        for(int i=0;i<n;i++){
            int o = word.charAt(i)-'a';
            Node t = cur.children[o];
            if(t==null){
                cur.children[o]=new Node();
            }
            cur=cur.children[o];
        }
        cur.ter=true;
    }
    
    public boolean search(String word) {
        if(word.isEmpty())return true;
        int n = word.length();
        Node cur = head;
        for(int i=0;i<n;i++){
            if(word.charAt(i)=='.'){
                StringBuilder t = new StringBuilder(word);
                boolean f = false;
                for(int c=0;c<26;c++){
                    if(cur.children[c]==null)continue;
                    t.setCharAt(i,(char)(c+'a'));
                    f|=search(t.toString());
                }
                return f;
            }
            int o = word.charAt(i)-'a';
            Node t = cur.children[o];
            if(t==null){
                return false;
            }
            cur=cur.children[o];
        }
        return cur.ter;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */