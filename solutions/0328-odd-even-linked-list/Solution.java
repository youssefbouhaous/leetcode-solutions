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
    public ListNode oddEvenList(ListNode head) {
        if(head==null)return null;
        ListNode even=null;
        ListNode e=null;
        ListNode odd=null;
        ListNode o=null;
        ListNode cur = head;
        int i = 0;
        while(cur != null){
            if(i%2==0){
                if((o==null)){
                    odd = cur;
                    o = cur;
                }
                else{
                    o.next = cur;
                    o = cur;
                }
            }
            else{
                if((e==null)){
                    even = cur;
                    e = cur;
                }
                else{
                    e.next = cur;
                    e = cur;
                }
            }
            cur = cur.next;
            i++;
        }
        o.next = even;
        if(e!=null)
        e.next=null;
        return odd;
    }
}