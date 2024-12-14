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
    public void pot(TreeNode node,List<TreeNode>tmp){
        if(node==null){
            return;
        }
        tmp.add(node);
        pot(node.left,tmp);
        pot(node.right,tmp);
    }
    public void flatten(TreeNode root) {
        if(root==null) return ;
        List<TreeNode> tmp=new ArrayList<>();
        pot(root,tmp);
        int n=tmp.size();
        for(int i=0;i<n-1;i++){
            tmp.get(i).left=null;
            tmp.get(i).right=tmp.get(i+1);
        }
        tmp.get(n-1).left=null;
        tmp.get(n-1).right=null;
    }
}