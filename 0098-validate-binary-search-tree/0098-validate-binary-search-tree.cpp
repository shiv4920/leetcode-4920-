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
    TreeNode*prev=nullptr;
    bool ans=true;
public:
    void fun(TreeNode*root1){
        if(root1==nullptr)
          return;
        fun(root1->left);
        if(prev==nullptr)
          prev=root1;
        else if(root1->val<=prev->val){
              ans=false;
        }
        prev=root1;
        fun(root1->right);
    }
    bool isValidBST(TreeNode* root) {
        prev=0;
        fun(root);
        return ans;
    }
};