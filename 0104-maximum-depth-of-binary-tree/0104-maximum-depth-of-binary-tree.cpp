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
public:
    int fun(TreeNode*root1){
        if(root1==nullptr)
           return 0;
        int lh=fun(root1->left);
        int rh=fun(root1->right);
        return 1+max(lh,rh);   
    }
    int maxDepth(TreeNode* root) {
        return fun(root);
    }
};