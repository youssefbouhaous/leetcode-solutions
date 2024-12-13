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
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode f=head;
        ListNode s=head.next;
        head=s;
        while(s!=null && f.next!=null){
            //if(s.next!=null && s.next.next==null){break;}
            f.next=(s.next==null)?null:s.next.next;
            if(s.next==null){
            s.next=f;
            break;}
            ListNode ss=s.next.next;
            if(ss==null){
                f.next=s.next;
                s.next=f;
                break;
            }
            ListNode ff=s.next;
            s.next=f;
            f=ff;
            s=ss;
        }
        return head;
    }
}