/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    void f(TreeNode node,List<Integer>ans){
        if(node==null){return;}
        ans.add(node.val);
        if(node.left!=null)f(node.left,ans);
        if(node.right!=null)f(node.right,ans);
        //ans.add(node.val);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer>ans=new ArrayList<>();
        if(root==null) return ans;
        f(root,ans);
        return ans;
    }
}