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
    bool fun(TreeNode*p1, TreeNode*q1){
        if(p1==nullptr&&q1==nullptr)
           return true;
        if(p1==nullptr ||q1==nullptr)
           return false;
        if(p1->val!=q1->val)
           return false;
        bool r1=fun(p1->left,q1->left);
        bool r2=fun(p1->right,q1->right);
        if(r1==true&&r2==true)
         return true;
        return false;         
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p,q);
    }
};