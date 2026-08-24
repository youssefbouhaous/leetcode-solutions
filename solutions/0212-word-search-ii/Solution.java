class Solution {
    Node head;
    class Node{
        String word;
        Node[] children = new Node[26];
    }
    void add(String s){
        Node cur = head;
        int n = s.length();
        for(int i=0;i<n;i++){
            int o = s.charAt(i)-'a';
            Node t = cur.children[o];
            if(t==null){
                cur.children[o]=new Node();
            }
            cur = cur.children[o];
        }
        cur.word=s;
    }
    boolean search(String s){
        Node cur = head;
        int n = s.length();
        for(int i=0;i<n;i++){
            int o = s.charAt(i)-'a';
            Node t = cur.children[o];
            if(t==null){
                return false;
            }
            cur = cur.children[o];
        }
        return cur.word!=null;
    }
    boolean[][] vis;
    int n;
    int m;
    // StringBuilder tmpStr=new StringBuilder();
    char[][] board;
    boolean valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    List<String> ans = new ArrayList<>();
    // Set<String> st = new HashSet<>();
    void f(int i,int j,Node cur){
        if(!valid(i,j) || vis[i][j])return;
        int o = board[i][j]-'a';
        cur=cur.children[o];
        if(cur==null)return;
        vis[i][j]=true;
        // tmpStr.append(board[i][j]);
        if(cur!=null && cur.word!=null){
            // String r = tmpStr.toString();
            ans.add(cur.word);
            cur.word=null;
        }
        if(cur!=null){
        f(i+1,j,cur);
        f(i-1,j,cur);
        f(i,j+1,cur);
        f(i,j-1,cur);
        }
        // tmpStr.deleteCharAt(tmpStr.length()-1);
        vis[i][j]=false;
    }
    public List<String> findWords(char[][] board, String[] words) {
        head = new Node();
        n=board.length;
        m=board[0].length;
        vis = new boolean[n][m];
        this.board=board;
        for(String s:words){
            add(s);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // found=false;
                f(i,j,head);
            }
        }
        return ans;
    }
}