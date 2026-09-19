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
    bool res=false;
public:
    void fun(TreeNode*root1,int sum,int targetSum){
        if(root1==nullptr)
         return;
        sum+=root1->val; 
        if(root1->left==nullptr&&root1->right==nullptr){
            if(sum==targetSum){
               res=true;
            }
            return;
        }
        fun(root1->left,sum,targetSum);
        fun(root1->right,sum,targetSum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        fun(root,0,targetSum);
        return res;

    }
};