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
    ListNode merge(ListNode left,ListNode right){
        ListNode tail = new ListNode();
        ListNode ans = tail;
        while(left!=null || right!=null){
            if(left==null){
                tail.next=right;
                right=right.next;
            }else if(right==null){
                tail.next=left;
                left=left.next;
            }
            else if(left.val<right.val){
                tail.next=left;
                left=left.next;
            }else{
                tail.next=right;
                right=right.next;
            }
            tail=tail.next;
        }
        return ans.next;
    }
    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null)return head;
        ListNode left = head;
        ListNode right = getMid(head);
        ListNode tmp = right.next;
        right.next=null;
        right=tmp;
        left=sortList(left);
        right=sortList(right);
        head = merge(left,right);
        return head;
    }

    ListNode getMid(ListNode node){
        ListNode slow = node;
        ListNode fast= node.next;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}