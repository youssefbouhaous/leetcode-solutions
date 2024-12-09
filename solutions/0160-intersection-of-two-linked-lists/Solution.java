/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode ans=null;
        if(headA==null || headB==null) return ans;
        Map<ListNode,ListNode>map1=new HashMap<>();
        Map<ListNode,ListNode>map2=new HashMap<>();
        ListNode ha=headA;
        ListNode hb=headB;
        while(ha.next!=null){
            map1.put(ha.next,ha);
            ha=ha.next;
        }
        while(hb.next!=null){
            map2.put(hb.next,hb);
            hb=hb.next;
        }
        while(ha==hb && ha!=null){
            ans=ha;
            //System.out.println(ha.val+" "+hb.val);
            ha=map1.get(ha);
            hb=map2.get(hb);
        }
        return ans;
    }
}