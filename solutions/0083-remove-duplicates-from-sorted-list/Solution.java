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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)return head;
        ListNode ans = head;
        ListNode pre = head;
        ListNode cur = head.next;
        while(cur!=null){
            if(cur.val==pre.val){
                pre.next = cur.next;
            }
            else
            pre = cur;
            cur = cur.next;
        }
        return ans;
    }
}