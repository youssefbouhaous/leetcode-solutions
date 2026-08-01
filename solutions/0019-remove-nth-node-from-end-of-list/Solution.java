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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode cur = head;
        int c = 0;
        while(cur!=null){
            c++;cur=cur.next;
        }
        System.out.println(c);
        cur = head;
        int cc = 0;
        if(c==n)return head.next;
        while(cur!=null){
            System.out.println(c);
            c--;
            if(n==c){
                cur.next = cur.next.next;
                return head;
            }
            cur = cur.next;
        }
        return head;
    }
}