/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    Map<Node,Node> st = new HashMap<>();
    Node clone(Node c){
        if( c==null){
            return null;
        }
        Node cloneC = new Node(c.val);
        st.put(c,cloneC);
        for(Node n:c.neighbors){
            if(st.get(n)!=null){
                cloneC.neighbors.add(st.get(n));
                continue;
            }
            Node cloneN = clone(n);
            if(cloneN!=null){
                cloneC.neighbors.add(cloneN);
            }
        }
        return cloneC;
    }
    public Node cloneGraph(Node node) {
        return clone(node);
    }
}