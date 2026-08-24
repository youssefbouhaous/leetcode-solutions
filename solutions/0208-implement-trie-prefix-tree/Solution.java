class Trie {
    class Node{
        boolean ter;
        Node[] children=new Node[26];
    }
    Node head;
    public Trie() {
        head = new Node();
    }
    
    public void insert(String word) {
        Node cur = head;
        int n = word.length();
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
        Node cur=head;
        int n = word.length();
        for(int i=0;i<n;i++){
            int o = word.charAt(i)-'a';
            Node t = cur.children[o];
            if(t==null){
                return false;
            }
            cur=cur.children[o];
        }
        return cur.ter;
    }
    
    public boolean startsWith(String word) {
        Node cur=head;
        int n = word.length();
        for(int i=0;i<n;i++){
            int o = word.charAt(i)-'a';
            Node t = cur.children[o];
            if(t==null){
                return false;
            }
            cur=cur.children[o];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */