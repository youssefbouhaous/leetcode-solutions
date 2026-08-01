/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> st = new HashSet<>();
        ListNode h = head;
        while(h!=null){
            if(st.contains(h))return true;
            st.add(h);
            h = h.next;
        }
        return false;
    }
}