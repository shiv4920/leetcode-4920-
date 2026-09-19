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
    void fun(TreeNode*root1,int sum){
        if(root1==nullptr)
          return;
        sum=sum*10+root1->val;
        if(root1->left==nullptr&&root1->right==nullptr){
            res+=sum;
           return;
        } 
        fun(root1->left,sum);
        fun(root1->right,sum);
        return;
    }
    int sumNumbers(TreeNode* root) {
        fun(root,0);
        return res;
    }
};