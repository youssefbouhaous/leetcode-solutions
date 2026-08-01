/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode h1, ListNode h2) {
        ListNode a = h1;
        ListNode b = h2;
        ListNode h = new ListNode();
        ListNode cur = h;
        while(a!=null || b!=null){
            if(a==null){
                h.next = new ListNode(b.val);
                h=h.next;
                b=b.next;
            }
            else if(b==null){
                h.next = new ListNode(a.val);
                a=a.next;
                h=h.next;
            }
            else{
                if(a.val<b.val){
                    h.next = new ListNode(a.val);
                    h=h.next;
                    a=a.next;
                }else{
                    h.next = new ListNode(b.val);
                    b=b.next;
                    h=h.next;
                }
            }
        }
        return cur.next;
    }
}