/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode*ans=nullptr;
public:
    void fun(TreeNode*root1,TreeNode*p,TreeNode*q){
        if(root1==nullptr)
         return;
        if(root1==p||root1==q){
          ans=root1;
          return;
        }
        if(root1->val<p->val){
            fun(root1->right,p,q);
        }else if(root1->val>q->val){
            fun(root1->left,p,q);
        }else{
            ans=root1;
            return;
        } 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     ans=nullptr;
     if(p->val>q->val)
       fun(root,q,p);
     else
       fun(root,p,q);
     return ans;      
    }
};