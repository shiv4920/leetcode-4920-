/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res=0;
public:
    int fun(TreeNode*root1){
        if(root1==nullptr)
          return 0;
        int left=fun(root1->left);
        int right=fun(root1->right);
        res=max(res,left+right);
        return 1+max(left,right);  
    }
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return res;

    }
};