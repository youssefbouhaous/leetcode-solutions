/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public void dfs(Node n){
        if(n==null)return;
        Node t = new Node(n.val);
        
    }
    public Node copyRandomList(Node head) {
        if(head == null) return head;
        Node n = new Node(head.val);
        Node nc = n;
        Node cur = head.next;
        HashMap<Node,Node> map = new HashMap<>();
        map.put(head,n);
        while(cur!=null){
            Node tmp = new Node(cur.val);
            map.put(cur,tmp);
            nc.next = tmp;
            nc = tmp;
            cur = cur.next;
        }
        cur = head;
        nc = n;
        while(cur!=null){
            nc.random = map.get(cur.random);
            cur = cur.next;
            nc = nc.next;
        }
        return n;
    }
}