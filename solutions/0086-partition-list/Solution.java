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
    public ListNode partition(ListNode head, int x) {
        if(head==null || head.next==null)return head;
        List<ListNode> l = new ArrayList<>();
        ListNode cur = head;
        ListNode h1 = new ListNode();
        ListNode h2 = new ListNode();
        ListNode hh = null;
        ListNode hh2= null;
        while(cur!=null){
            if(cur.val<x){
                ListNode tmp = new ListNode(cur.val);
                h1.next=tmp;
                h1=tmp; 
                if(hh==null)hh=tmp;
            }else{
                ListNode tmp = new ListNode(cur.val);
                h2.next=tmp;
                h2=tmp;
                if(hh2==null)hh2=tmp;
            }
            cur = cur.next;
        }
        h1.next=hh2;
        if(hh==null)
        return hh2;
        return hh;
    }
}